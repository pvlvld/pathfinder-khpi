#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || lst->next == NULL) return lst;

    int length = mx_list_size(lst);

    for (int i = 0; i < length - 1; i++) {
        t_list *current = lst;
        for (int j = 0; j < length - i - 1; j++) {
            if (cmp(current->data, current->next->data)) mx_swap_list_data(current, current->next);
            current = current->next;
        }
    }

    return lst;
}
