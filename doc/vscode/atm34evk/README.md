# Setting Up `tasks.json` for ATM34 in VS Code

Follow these steps to configure the `tasks.json` file for ATM34 in Visual Studio Code (VS Code):

---

## 1. Install VS Code
Download and install VS Code from the official website:
[https://code.visualstudio.com/download](https://code.visualstudio.com/download).

---

## 2. Open a Folder
- Launch VS Code.
- Open a new folder by navigating to `File -> Open Folder`.

---

## 3. Configure Tasks
- Press `CTRL+SHIFT+P` and type **"Tasks: Configure Task"**.
- Select **"Create tasks.json file"**.

---

## 4. Replace with Zephyr Tasks
- Choose **MSBuild**, and a sample `tasks.json` file will open.
- Replace its contents with the existing `openair/doc/vscode/atm34evk/tasks.json` file.

---

## 5. Access Build, Flash, and West Initialize
Press `CTRL+SHIFT+P` to display options in the dropdown menu for:
- **Build**
- **Flash**
- **West Initialize**

---

## 6. West Initialize
1. Click on **West Init**.
2. Paste the repository link (default is `git@github.com:Atmosic/atmosic-private.git`) and specify the branch name.
3. After initializing, click on **West Update**.

---

## 7. West Build
- When building dependencies, provide the following arguments:
  - Board name
  - Sample path
  - Extra config files
  - Sysbuild arguments (found in `sample.yml`).

**Note**: Once an argument is provided, it is cached until the user modifies it.

---

## 8. West Flash
- Various flash options will appear depending on the build case.
- Provide the following details:
  - Board number
  - Board name
  - Sample.

---
