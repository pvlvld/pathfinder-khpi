#include "../inc/libmx.h"

t_list *mx_merge_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || lst->next == NULL) return lst;

    t_list *slow = lst;
    t_list *fast = lst->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    t_list *second = slow->next;
    slow->next = NULL;

    lst = mx_sort_list(lst, cmp);
    second = mx_sort_list(second, cmp);

    return mx_merge_sorted_lists(lst, second, cmp);
}
