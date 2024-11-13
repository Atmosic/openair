/**
 *******************************************************************************
 *
 * @file atm_utils_slist.h
 *
 * @brief ATM singly linked list
 *
 * Copyright (C) Atmosic 2022-2024
 *
 *******************************************************************************
 */

#pragma once

/**
 * @defgroup ATM_UTILS_SLIST ATM singly linked list
 * @ingroup ATM_UTILS
 * @brief ATM singly linked list
 *
 * @{
 *
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Singly linked list node structure
typedef struct atm_slist_node_s {
    /// Pointer to the next node
    struct atm_slist_node_s *next;
} atm_slist_node_t;

/// Singly linked list structure
typedef struct {
    /// Pointer to the head
    atm_slist_node_t *head;
    /// Pointer to the tail
    atm_slist_node_t *tail;
} atm_slist_t;

/**
 * @brief Initialize a singly linked list
 *
 * @param[in] list Pointer to the list
 */
__NONNULL_ALL
void atm_slist_init(atm_slist_t *list);

/**
 * @brief The total number of nodes in the list.
 *
 * @param[in] list Pointer to the list
 * @return Number of nodes
 */
uint16_t atm_slist_size(atm_slist_t const *list);

/**
 * @brief Insert a node to be the head
 *
 * @param[in] list Pointer to the list
 * @param[in] new_node Pointer to the new node
 */
__NONNULL_ALL
void atm_slist_insert_to_head(atm_slist_t *list, atm_slist_node_t *new_node);

/**
 * @brief Insert a node to be the tail
 *
 * @param[in] list Pointer to the list
 * @param[in] new_node Pointer to the new node
 */
__NONNULL_ALL
void atm_slist_insert_to_tail(atm_slist_t *list, atm_slist_node_t *new_node);

/**
 * @brief Insert a node before the reference node
 *
 * @param[in] list Pointer to the list
 * @param[in] ref_node Pointer to the reference node
 * @param[in] new_node Pointer to the new node
 * @return True if found the reference node and insert successfully
 */
__NONNULL(1, 3)
bool atm_slist_insert_before(atm_slist_t *list,
    atm_slist_node_t const *ref_node, atm_slist_node_t *new_node);

/**
 * @brief Remove a given node
 *
 * @param[in] list Pointer to the list
 * @param[in] rm_node Pointer to the given node
 * @return True if found the given node
 */
__NONNULL(1)
bool atm_slist_remove(atm_slist_t *list, atm_slist_node_t const *rm_node);

/**
 * @brief Append src to dst.
 *
 * @param[in] dst Pointer to the destination list
 * @param[in] src Pointer to the list to be appended
 */
__NONNULL_ALL
void atm_slist_list_append(atm_slist_t *dst, atm_slist_t *src);

/**
 * @brief Get the following node of the reference node
 *
 * @param[in] ref_node Pointer to the reference node
 * @return The pointer to the next node
 */
__NONNULL_ALL
__INLINE atm_slist_node_t *atm_slist_next(atm_slist_node_t const *ref_node)
{
    return ref_node->next;
}

/**
 * @brief Get the head from the list
 *
 * @param[in] list Pointer to the list
 * @return The pointer to the head
 */
__NONNULL_ALL
__INLINE atm_slist_node_t *atm_slist_head(atm_slist_t const *list)
{
    return list->head;
}

/**
 * @brief Check if the list is empty
 *
 * @param[in] list Pointer to the list
 * @return True if the list is empty
 */
__NONNULL_ALL
__INLINE bool atm_slist_is_empty(atm_slist_t const *list)
{
    return (list->head == NULL);
}

/**
 * @brief Pop the head from the list
 *
 * @param[in] list Pointer to the list
 * @return The pointer to the head
 */
__NONNULL_ALL
__INLINE atm_slist_node_t *atm_slist_pop_head(atm_slist_t *list)
{
    atm_slist_node_t *head = atm_slist_head(list);
    atm_slist_remove(list, head);
    return head;
}

/// Macro to create a for-loop for a atm_slist
#define FOR_ATM_SLIST(atm_list, type, hdlr) \
    for (type hdlr = (type)atm_slist_head(&atm_list); hdlr; \
	hdlr = (type)atm_slist_next(&hdlr->hdr)) \

/// Macro to create a for-loop for pop atm_slist FIFO
#define FOR_ATM_SLIST_POP(atm_list, type, hdlr) \
    for (type hdlr = (type)atm_slist_pop_head(&atm_list); hdlr; \
	hdlr = (type)atm_slist_pop_head(&atm_list)) \

#ifdef __cplusplus
}
#endif

/// @}
