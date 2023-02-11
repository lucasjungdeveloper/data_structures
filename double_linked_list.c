#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int number;
    struct node *next;
    struct node *previous;
} node;

void add_to_start(node **start, node **end, int number);
void add_to_end(node **start, node **end, int number);
void print_list_from_start(node *start);
void print_list_from_end(node *end);
void free_list(node *start);

int main(void) {
    node *start = NULL;
    node *end = NULL;

    add_to_end(&start, &end, 1);
    add_to_end(&start, &end, 2);
    add_to_start(&start, &end, 0);
    add_to_end(&start, &end, 3);
    add_to_end(&start, &end, 4);

    printf("From start:\n");
    print_list_from_start(start);

    printf("From end:\n");
    print_list_from_end(end);

    free_list(start);
}

void add_to_start(node **start, node **end, int number) {
    if (*start == NULL) {
        node *n = malloc(sizeof(node));
        n->number = number;
        n->next = NULL;
        n->previous = NULL;

        *start = n;
        *end = n;
        return;
    }

    node *n = malloc(sizeof(node));
    n->number = number;
    n->previous = *end;
    n->next = NULL;

    (*end)->next = n;
    *end = n;
}

void add_to_end(node **start, node **end, int number) {
    if (*start == NULL) {
        node *n = malloc(sizeof(node));
        n->number = number;
        n->next = NULL;
        n->previous = NULL;

        *start = n;
        *end = n;
        return;
    }

    node *n = malloc(sizeof(node));
    n->number = number;
    n->previous = NULL;
    n->next = *start;

    (*start)->previous = n;
    *start = n;
}

void print_list_from_start(node *start){
    while (start != NULL){
        printf("%i\n", start->number);
        start = start->next;
    }
}

void print_list_from_end(node *end){
    while (end != NULL){
        printf("%i\n", end->number);
        end = end->previous;
    }
}

void free_list(node *start) {
    while (start != NULL){
        node *tmp = start->next;
        free(start);
        start = tmp;
    }
}