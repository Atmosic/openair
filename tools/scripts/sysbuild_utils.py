#!/usr/bin/env python
"""
@file sysbuild_utils.py

@Parse sysbuild utility for atm test items

Copyright (C) Atmosic 2025
"""
import argparse
from glob import glob
import os
from pathlib import Path
import re
import signal
import subprocess
import sys
import yaml

ZEPHYR_BASE = os.getenv("ZEPHYR_BASE")
if not ZEPHYR_BASE:
    # set ZEPHYR_BASE.
    ZEPHYR_BASE = os.path.join(str(Path(__file__).resolve().parents[3]),
        'zephyr')
    # Propagate this decision to child processes.
    os.environ['ZEPHYR_BASE'] = ZEPHYR_BASE
WEST_DIR = str(Path(ZEPHYR_BASE).resolve().parents[0])
TEMPLATE_DIR = os.path.join(WEST_DIR, 'openair', 'tools', 'scripts', 'sysbuild')

REPO_LIST = {
    'zephyr':  ['samples'],
    'openair': ['applications', 'samples'],
    'atmosic-internal': ['applications', 'samples'],
    'atmosic-private': ['applications', 'samples'],
}

class TestInfo:
    def __init__(self, rootpath, filepath, exp_items, debug):
        self.rootpath = rootpath
        self.ex_path = os.path.dirname(filepath)
        self.item_base = self.ex_path.replace('/', '.')
        self.sample_file = os.path.join(WEST_DIR, rootpath, filepath)
        self.template_file = os.path.join(TEMPLATE_DIR, filepath)
        self.debug = debug
        self.prj_file = os.path.join(WEST_DIR, rootpath, self.ex_path,
            'prj.conf')
        self.support_bt = False
        self.atm_items = []
        self.exp_items = exp_items
        self._init()

    def show_info(self):
        print(f"[{self.rootpath}][{self.ex_path}]")
        print(f"    rootpath = {self.rootpath}")
        print(f"    sample_file = {self.sample_file}")
        if self.rootpath == 'zephyr':
            print(f"    template_file = {self.template_file}")
        print(f"    ex_path = {self.ex_path}")
        print(f"    item_base = {self.item_base}")
        print(f"    prj_file = {self.prj_file}")
        print(f"    support_bt = {self.support_bt}")
        print(f"    atm_items = {self.atm_items}")

    def gen_info(self):
        loaded_data, tests = self.get_sample_data(self.sample_file)
        _, tmp_tests = self.get_sample_data(self.template_file)
        updated = False
        if not tmp_tests:
            print("Cannot find tests label in {self.template_file}")
        if not tests:
            tests = {}
        loaded_data.update({'tests': tests})
        for tmp_test in tmp_tests:
            if not tmp_test in tests:
                item_obj = tmp_tests[tmp_test]
                loaded_data['tests'].update({tmp_test: item_obj})
                print(f"append test item [{tmp_test}] to {self.sample_file}")
                updated = True
        if updated:
            with open(self.sample_file, 'w', encoding="utf-8") as f:
                yaml.dump(loaded_data, f)

    def _init(self):
        self.check_support_bt()
        self.check_atm_items()

    def check_support_bt(self):
        if not os.path.exists(self.prj_file):
            print(f"[{self.prj_file}] not exist")
            return False
        with open(self.prj_file, 'r', encoding="utf-8") as f:
            for line in f.readlines():
                if 'CONFIG_BT=y' in line:
                    self.support_bt = True
                    break
        return True

    def update_atm_items(self, item_name):
        if not item_name in self.atm_items:
            self.atm_items.append(item_name)

    def get_sample_data(self, filepath):
        loaded_data = None
        tests = None
        if not os.path.exists(filepath):
            print(f"[{filepath}] not exists, ignore")
        else:
            with open(filepath, 'r', encoding="utf-8") as f:
                loaded_data = yaml.safe_load(f)
                tests = loaded_data.get('tests')
        return loaded_data, tests

    def check_atm_items(self):
        _, tests = self.get_sample_data(self.sample_file)
        if tests:
            if self.exp_items:
                for exp_item in self.exp_items:
                    if exp_item in tests:
                        self.update_atm_items(exp_item)
            else:
                for item_name in tests:
                    if ".atm" in item_name:
                        self.update_atm_items(item_name)


def parse_args(args=None, namespace=None):
    parser = argparse.ArgumentParser(description='Zephyr Twister Sysbuild Tool')
    subparsers = parser.add_subparsers(dest='opcode')
    list_parser = subparsers.add_parser(
        'list',
        help="list atm test item info")
    gen_parser = subparsers.add_parser(
        'gen',
        help=f"gen atm test items from known support list")
    parser.add_argument(
        "-d", "--debug", action="store_true", default=False,
        help="Enable debug")
    parser.add_argument(
        "-r", "--repo_root", type=str,
        metavar="repository folder under zephyrproject", required=False,
        help="EX: openair or atmosic-internal or zephyr, default: openair,"
            " atmosic-internal, atmosic-private, zephyr")
    parser.add_argument(
        "-t", "--test_dir", type=str,
        metavar="sample folder path relative to repository folder (-r repo_root"
            ")", required=False,
        help="EX: samples/bluetooth/hci_uart of zephyr, default: searching from"
            " samples/** of zephyr (openair/tools/sysbuild/samples/**) and"
            " samples/** and application/** of repo_root")
    parser.add_argument(
        "-e", "--exp_items", type=str,
        metavar="atmosic test items that could be found in sample.yaml under "
            "sample folder path (-t test_dir)", required=False,
        help="EX: xxxx.xxxx.atm or xxxx.xxxx.atm,xxxx.xxxx.atm.mcuboot, default"
        ": all atm test items")
    return parser.parse_args(args, namespace)

def safe_exit(msg=None):
    # do some thing before exit
    if msg:
        print(f"[Exit] {msg}")
    sys.exit(1)

def clean_exit(signum, frame):
    try:
        msg = "\nExit, or not exit, that is the question! (y/n)> "
        if input(msg).lower().startswith('y'):
            # do some thing before exit
            safe_exit()
    except KeyboardInterrupt:
        safe_exit()

def collect_test_info(repo_list, exp_items=None, debug=False):

    test_info_list = []
    for repo_name in repo_list:
        if debug:
            print(f"repo: {repo_name}")
        if repo_name == 'zephyr':
            repo_path = TEMPLATE_DIR
        else:
            repo_path = os.path.join(WEST_DIR, repo_name)
        if debug:
            print(f"repo_path: {repo_path}")
        check_dir_list = repo_list[repo_name]
        if debug:
            print(f"check_dir_list: {check_dir_list}")
        if os.path.exists(repo_path):
            os.chdir(repo_path)
            for dir_name in check_dir_list:
                if os.path.exists(os.path.join(repo_path, dir_name)):
                    if debug:
                        print(f"check_dir: {dir_name}/**/sample.yaml")
                    file_list = glob(f"{dir_name}/**/sample.yaml",
                        recursive=True)
                    if debug:
                        print(f"file_list={file_list}")
                    for file in file_list:
                        if repo_name == 'zephyr':
                            file = file.replace(TEMPLATE_DIR,
                                os.path.join(WEST_DIR, repo_name))
                        if debug:
                            print(f"file: {file}")
                        test_info = TestInfo(repo_name, file, exp_items, debug)
                        test_info_list.append(test_info)
            os.chdir(WEST_DIR)
        else:
            print(f"{repo_path} not exists")
            safe_exit()
    return test_info_list

def perform_handler(opcode, test_info_list):
    for test_info in test_info_list:
        match opcode:
            case 'list':
                test_info.show_info()
            case 'gen':
                repo_path = os.path.join(WEST_DIR, test_info.rootpath)
                if not os.path.exists(repo_path):
                    print(f"{repo_path} not exist")
                os.chdir(repo_path)
                test_info.gen_info()
                os.chdir(WEST_DIR)

def init(args):
    dir_list = None
    if args.test_dir:
        dir_list = args.test_dir.split(',')
    repo_list = {}
    if args.repo_root:
        repos = args.repo_root.split(',')
        for repo in repos:
            if not dir_list:
                repo_dir_list = REPO_LIST.get(repo)
                repo_list.update({repo: repo_dir_list})
            else:
                repo_list.update({repo: dir_list})
    else:
        repo_list = REPO_LIST
        if dir_list:
            for repo in REPO_LIST:
                repo_list.update({repo: dir_list})
    if args.exp_items:
        exp_items = args.exp_items.split(',')
    else:
        exp_items = None
    debug = False
    if args.debug:
        debug = args.debug
    return collect_test_info(repo_list, exp_items, debug)

def main(args=None, namespace=None):
    signal.signal(signal.SIGINT, clean_exit)
    args = parse_args(args, namespace)
    if args.opcode == 'gen':
        if not args.repo_root or args.repo_root != 'zephyr':
            safe_exit("Generate test item support zephyr only")
    test_info_list = init(args)
    perform_handler(args.opcode, test_info_list)

if __name__ == "__main__":
    if sys.version_info[0] < 3:
        safe_exit(f"Requires Python 3", 2)
    main()
