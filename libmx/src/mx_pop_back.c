#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (*head != NULL && (*head)->next != NULL) {
        t_list *p_list_node = *head;
        while (p_list_node->next->next != NULL) p_list_node = p_list_node->next;
        t_list *temp = p_list_node->next;
        p_list_node->next = NULL;
        free(temp);
    } else if (*head != NULL) {
        free(*head);
        *head = NULL;
    }
}
