#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *rear = NULL, *front=NULL;

struct node *enQueue(){
    int num;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    newNode -> data = num;
    if(front == NULL){
        newNode -> next = NULL;
        front = newNode;
        rear = front;
    }
    else{
        rear -> next = newNode;
        newNode->next = NULL;
        rear = newNode;
    }
}

struct node *deQueue(){
    struct node *temp;
    if(front == NULL){
        printf("Stack Underflow");
    }
    else{
        if(front->next==NULL){
            free(front);
            front = NULL;
            rear = NULL;
        }
        else{
            temp = front;
            front = front->next;
        }
    }
}

struct node *display(){
    struct node *ptr;
    if(front == NULL){
        printf("Stack is Empty!!!");
    }
    else{
        ptr = front;
        while(ptr -> next != NULL){
            printf("%d\t",ptr->data);
            ptr = ptr -> next;
        }
        printf("%d\n",ptr->data);
    }
}


int main(){
    int choice;
    while(1){
        printf("\n**********MAIN MENU**********");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid Input!!! Try Again.");
        }
    }
    return 0;
}

