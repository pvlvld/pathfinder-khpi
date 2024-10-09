#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *front_node = mx_create_node(data);
    if (front_node == NULL) return;

    front_node->next = *list;
    *list = front_node;
}
