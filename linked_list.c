#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int number;
    struct node *next;
} node;

void add_node_to_end(node** list, int number);
void print_list(node* list);
void free_list(node* list);

int main(void) {
    node *list = NULL;

    add_node_to_end(&list, 1);
    add_node_to_end(&list, 2);
    add_node_to_end(&list, 3);
    add_node_to_end(&list, 4);

    print_list(list);

    free_list(list);
    return 0;
}

void add_node_to_end(node** list, int number) {
    // Allocates memory for a node "n" and instantiate it
    node* n = malloc(sizeof(node));
    n->number = number;
    n->next = NULL;

    if (*list == NULL) {
        // Changes the address of the pointer pointed by "node **list"
        // to the same address pointed by "n"
        *list = n;

        return;
    }

    // Copies "*list" pointed value to avoid changing
    // the list variable on the main function
    node* node = *list;

    while (node->next != NULL) {
        node = node->next;
    }

    // Changes the last node's "next" pointer to the value of "n"
    node->next = n;
}

void print_list(node* list) {
    while (list != NULL) {
        printf("%i\n", list->number);
        list = list->next;
    }
}

void free_list(node *list) {
    while (list != NULL) {
        // Temporarily saves value of next node to safely free list's address
        node* tmp = list->next;

        free(list);
        list = tmp;
    }
}
