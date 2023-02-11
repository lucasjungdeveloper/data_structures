#include "stdlib.h"
#include "stdio.h"

typedef struct node {
    int number;
    struct node *previous;
} node;

void push(node **tail, node **head, int number);

int pop(node **head);

void print_queue(node *head);

void free_queue(node *head);

int main(void) {
    node *head = NULL;
    node *tail = NULL;

    push(&tail, &head, 1);
    push(&tail, &head, 2);
    push(&tail, &head, 3);

    print_queue(head);

    int popped = pop(&head);

    printf("\nPopped %i\n\n", popped);

    print_queue(head);

    free_queue(head);
}

void push(node **tail, node **head, int number) {
    if (*head == NULL) {
        node *n = malloc(sizeof(node));
        n->number = number;
        n->previous = NULL;
        *head = n;
        *tail = n;
        return;
    }

    node *n = malloc(sizeof(node));
    n->number = number;
    n->previous = NULL;
    (*tail)->previous = n;
    *tail = n;
}

int pop(node **head) {
    int popped = (*head)->number;
    node *tmp = (*head)->previous;
    free(*head);
    *head = tmp;
    return popped;
}

void print_queue(node *head) {
    while (head != NULL) {
        printf("%i\n", head->number);
        head = head->previous;
    }
}

void free_queue(node *head) {
    while (head != NULL) {
        node *tmp = head->previous;
        free(head);
        head = tmp;
    }
}