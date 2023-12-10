#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *start=NULL;

struct node *insertAtBeginning(struct node *start){
    int num;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    newNode -> data = num;
    newNode -> prev = NULL;
    if(start == NULL){
        newNode -> next = NULL;
        start = newNode;
    }
    else{
        newNode-> next = start;
        start = newNode;
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    if(start==NULL){
        printf("List is Empty!!\n");
    }
    else{
        ptr =start;
        while(ptr->next!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr -> next;
        }
        printf("%d\t",ptr->data);
    }
}

struct node *insertAtEnd(struct node *start){
    struct node *newNode, *ptr;
    int num;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    newNode->data = num;
    newNode->next = NULL;
    if(start == NULL){
        newNode->prev = NULL;
        start = newNode;
    }
    else{
        ptr = start;
        while(ptr->next!=NULL){
            ptr =ptr ->next;
        }
        newNode -> prev = ptr;
        ptr ->next = newNode;
    }
    return start;
}

struct node *insertAfterSpecific(struct node *start){
    int num, specificNUm;
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    printf("Enter the data after which you want to insert the node: ");
    scanf("%d",&specificNUm);
    newNode -> data = num;
    ptr = start;
    while(ptr->data!=specificNUm){
        ptr = ptr -> next;
    }
    newNode->prev = ptr;
    ptr ->next = newNode;
    newNode->next = ptr ->next;
}

struct node *deleteBeginning(struct node *start){
    struct node *temp;
    if(start == NULL){
        printf("Linked List is Empty! Nothing to delete");
    }
    else{
        temp = start;
        start = temp->next;
        free(temp);
    }
    return start;
}


struct node *deleteEnd(struct node *start){
    struct node *prePtr, *postPtr;
    if(start == NULL){
        printf("List is Empty NOthing to be deleted!!!");
    }
    else{
        postPtr = start;
        if(postPtr -> next == NULL){
            free(postPtr);
            start = NULL;
        }
        else{
            while(postPtr->next!=NULL){
                prePtr = postPtr;
                postPtr = postPtr -> next;
            }
            prePtr -> next = NULL;
            postPtr -> prev = NULL;
            free(postPtr);
        }
    }
}

struct node *deleteSpecific(struct node *start){
    int num;
    struct node *temp, *prePtr, *postPtr;
    printf("Enter the data you want to delete: ");
    scanf("%d",&num);
    postPtr = start;
    while(postPtr->data!=num){
        prePtr = postPtr;
        postPtr = postPtr->next;
    }
    temp = postPtr;
    postPtr = postPtr ->next;
    prePtr -> next = postPtr;
    postPtr ->prev = prePtr;
    free(temp);
}


int main(){
    int choice;
    while(1){
        printf("\n***********MAIN MENU**********\n");
        printf("1. Insert At Beginning.\n");
        printf("2. Display\n");
        printf("3. Insert At End.\n");
        printf("4. Insert AFter Specific.\n");
        printf("5. Delete At Beginning.\n");
        printf("6. Delete At End.\n");
        printf("7. Delete At Specific.\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            start = insertAtBeginning(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            start = insertAtEnd(start);
            break;
        case 4:
            insertAfterSpecific(start);
            break;
        case 5:
            start = deleteBeginning(start);
            break;
        case 6:
            start = deleteEnd(start);
            break;
        case 7:
            deleteSpecific(start);
            break;
        case 8:
            exit(1);
        
        default:
            printf("Wrong Input!!! Try Again");
        }
    }
    return 0;
}