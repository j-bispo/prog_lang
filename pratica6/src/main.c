/*
Program: Linked List Implementation
Author: Joseph Alberto
Date: May 12, 2025
Description: This program implements a simple linked list in C. It includes functions to create a list, insert elements, delete elements, and print the list. The program also demonstrates the use of a stack and queue data structure using linked lists.
License: CC BY-SA
*/

// C code

#include <stdio.h>
#include <stdlib.h>
#include "./include/list.h"

typedef struct {
   tNode* top;
} tStack;

void push(tStack *stack, int x){
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    new_node->data = x;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(tStack *stack){
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1; // or some error value
    }
    tNode* temp = stack->top;
    int popped_value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped_value;
}

typedef struct {
    tNode* front;
    tNode* rear;
} tQueue;

void insert_rear(tQueue *q, int x){
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    new_node->data = x;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int remove_front(tQueue *q){
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1; // or some error value
    }
    tNode* temp = q->front;
    int removed_value = temp->data;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return removed_value;
}

int main() {
    // Lista
    printf("== Lista ==\n");
    tList list = create_list();
    insert_list(&list, 10);
    insert_list(&list, 30);
    insert_list(&list, 20);
    insert_list(&list, 40);
    insert_list(&list, 50);
    print_list(&list);
    free_list(&list);

    // Pilha
    printf("\n== Pilha ==\n");
    tStack stack = { NULL };
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));

    // Fila
    printf("\n== Fila ==\n");
    tQueue queue = { NULL, NULL };
    insert_rear(&queue, 100);
    insert_rear(&queue, 200);
    insert_rear(&queue, 300);
    printf("Dequeue: %d\n", remove_front(&queue));
    printf("Dequeue: %d\n", remove_front(&queue));
    printf("Dequeue: %d\n", remove_front(&queue));
    printf("Dequeue: %d\n", remove_front(&queue));

    return 0;
}