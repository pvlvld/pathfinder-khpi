#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *back_node = mx_create_node(data);
    if (back_node == NULL) return;

    if (*list == NULL) {
        *list = back_node;
        return;
    }

    t_list *p_list_node = *list;
    while (p_list_node->next != NULL) p_list_node = p_list_node->next;
    p_list_node->next = back_node;
}
