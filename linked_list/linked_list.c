#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int n;
    struct node* next;
} node;

int search(int n, node* list) {
    node* ptr = list;

    while(ptr != NULL) {
        if(ptr->n == n)
            return 1;
        ptr = ptr->next;
    }

    return -1;
}

void push(int n, node* list) {
    node* ptr = list;

    while(ptr != NULL) {
        if(ptr->next == NULL)
            break;
        ptr = ptr->next;
    }

    node* next = malloc(sizeof(node));
    next->n = n;
    next->next = NULL;

    ptr->next = next; 
}

void pop(node* list) {
    node* ptr = list;
    node* before = list;
    if(ptr == NULL) {
        printf("Sorry, but the list is empty");
        return;
    }

    while(ptr != NULL) {
        if(ptr->next == NULL)
            break;
        before = ptr;
        ptr = ptr->next;
    }


    before->next = NULL;
    free(ptr);
}

void print(node* list) {
    node* ptr = list;
    while(ptr != NULL) {
        printf("n is %d\n", ptr->n);
        ptr = ptr->next;
    }
}

int main() {
    node linked_list = {
        .n = 1,
        .next = NULL
    };


    push(2, &linked_list);
    push(3, &linked_list);
    push(4, &linked_list);
    push(5, &linked_list);

    if(search(3, &linked_list) == 1)
        printf("The number %d exists in list\n", 3);
    if(search(15, &linked_list) == -1)
        printf("The number %d not exists in list\n", 15);

    print(&linked_list);

    printf("Execute pop\n");
    pop(&linked_list);
    print(&linked_list);
    printf("Execute pop\n");
    pop(&linked_list);
    print(&linked_list);

    return 0;
}

