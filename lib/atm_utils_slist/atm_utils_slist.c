/**
 *******************************************************************************
 *
 * @file atm_utils_slist.c
 *
 * @brief Singly linked list
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#include "arch.h"
#include "atm_utils_slist.h"

void atm_slist_init(atm_slist_t *list)
{
    list->head = NULL;
    list->tail = NULL;
}

uint16_t atm_slist_size(atm_slist_t const *list)
{
    if (!list) {
	return 0;
    }

    uint16_t count = 0;
    atm_slist_node_t *curr = list->head;
    while (curr) {
	curr = curr->next;
	count++;
    }
    return count;
}

void atm_slist_insert_to_head(atm_slist_t *list, atm_slist_node_t *new_node)
{
    if (atm_slist_is_empty(list)) {
	list->tail = new_node;
    }

    new_node->next = list->head;
    list->head = new_node;
}

void atm_slist_insert_to_tail(atm_slist_t *list, atm_slist_node_t *new_node)
{
    if (atm_slist_is_empty(list)) {
	list->head = new_node;
    } else {
	list->tail->next = new_node;
    }
    list->tail = new_node;
    new_node->next = NULL;
}

bool atm_slist_insert_before(atm_slist_t *list,
    atm_slist_node_t const *ref_node, atm_slist_node_t *new_node)
{
    if (!ref_node || (list->head == ref_node)) {
	atm_slist_insert_to_head(list, new_node);
	return true;
    }

    atm_slist_node_t *prev = list->head;
    atm_slist_node_t *curr = list->head;
    while (curr) {
	if (curr == ref_node) {
	    prev->next = new_node;
	    new_node->next = curr;
	    return true;
	}
	prev = curr;
	curr = curr->next;
    }

    return false;
}

bool atm_slist_remove(atm_slist_t *list, atm_slist_node_t const *rm_node)
{
    atm_slist_node_t *curr = list->head;
    atm_slist_node_t *prev = NULL;

    while (curr) {
	if (curr == rm_node) {
	    if (!prev) {
		list->head = rm_node->next;
	    } else {
		prev->next = rm_node->next;
	    }

	    if (rm_node == list->tail) {
		list->tail = prev;
	    }
	    return true;
	}
	prev = curr;
	curr = curr->next;
    }
    return false;
}

void atm_slist_list_append(atm_slist_t *dst, atm_slist_t *src)
{
    ASSERT_ERR(!atm_slist_is_empty(src));

    if (atm_slist_is_empty(dst)) {
	dst->head = src->head;
    } else {
	dst->tail->next = src->head;
    }
    dst->tail = src->tail;
    src->head = NULL;
}
