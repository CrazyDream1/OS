#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lincked_list
{
    int value;
    struct Lincked_list* next;
};

struct Lincked_list* node_create(int val)
{
    struct Lincked_list* a = (struct Lincked_list*)malloc(sizeof (struct Lincked_list));
    a->value = val;
    a->next = NULL;
    return a;
}

void node_destruct(struct Lincked_list* list)
{
    list->next = NULL;
    free(list);
}

void print_list(struct Lincked_list* a)
{
    if (a != NULL) printf ("%d ", a->value);
    else return;
    while (a->next != NULL)
    {
        a = a -> next;
        printf ("%d ", a->value);
    }
    printf("\n");
}

void insert_node(struct Lincked_list** list, int index, struct Lincked_list* node)
{
    if (*list == NULL) {
        *list = node;
        return;
    }
    if (index == 0) {
        node->next = *list;
        *list = node;
        return;
    }
    struct Lincked_list* local = *list;
    for (int i = 0; i < index - 1 && (*list)->next != NULL; i++)
    {
        local = local->next;
    }
    struct Lincked_list* t = local->next;
    local->next = node;
    node->next = t;
}

void delete_node(struct Lincked_list** list, int index)
{
    if (index == 0) {
        struct Lincked_list* del = *list;
        (*list) = (*list)->next;
        node_destruct(del);
        return;
    }
    struct Lincked_list* local = *list;
    for (int i = 0; i < index - 1 && (*list)->next != NULL; i++)
    {
        local = local->next;
    }
    struct Lincked_list* t = local->next;
    if (local->next != NULL) {
        local->next = local->next->next;
        node_destruct(t);
    }
}

int main(int argc, char *argv[])
{
    struct Lincked_list* a = NULL;
    insert_node(&a, 0, node_create(5));
    insert_node(&a, 1, node_create(7));
    insert_node(&a, 2, node_create(1));
    insert_node(&a, 3, node_create(4));
    print_list(a);
    delete_node(&a, 0);
    print_list(a);
    return 0;
}
