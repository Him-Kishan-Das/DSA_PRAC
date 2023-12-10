#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *insert(struct node *start) {
    struct node *newNode, *postPtr, *prePtr;
    int num;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data: ");
    scanf("%d", &num);
    newNode->data = num;
    postPtr = start;
    if (start == NULL) {
        newNode->next = NULL;
        start = newNode;
    } else {
        if (newNode->data < start->data) {
            newNode->next = start;
            start = newNode;
        } else {
            while (postPtr->next != NULL && postPtr->data < newNode->data) {
                prePtr = postPtr;
                postPtr = postPtr->next;
            }
            if (postPtr->data > newNode->data) {
                prePtr->next = newNode;
                newNode->next = postPtr;
            } else {
                postPtr->next = newNode;
                newNode->next = NULL;
            }
        }
    }
    return start;
}

void display(struct node *start) {
    struct node *temp;
    temp = start;
    if (start == NULL) {
        printf("List is Empty!!!");
    } else {
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("**********MAIN MENU*********\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = insert(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Input!!!!\n");
        }
    }
    return 0;
}
