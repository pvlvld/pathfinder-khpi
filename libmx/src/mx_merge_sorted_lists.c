#include "../inc/libmx.h"

t_list *mx_merge_sorted_lists(t_list *list1, t_list *list2, bool (*cmp)(void *, void *)) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    t_list *merged = NULL;
    if (!cmp(list1->data, list2->data)) {
        merged = list1;
        merged->next = mx_merge_sorted_lists(list1->next, list2, cmp);
    } else {
        merged = list2;
        merged->next = mx_merge_sorted_lists(list1, list2->next, cmp);
    }

    return merged;
}
