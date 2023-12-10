#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *push(struct node *top){
    struct node *newNode;
    int num;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    newNode -> data = num;
    
    if(top == NULL){
        newNode ->next = NULL;
        top = newNode;
    }
    else{
        newNode -> next = top;
        top = newNode;
    }
    return top;
}


struct node *pop(struct node *top){
    struct node *temp;
    if(top == NULL){
        printf("Stack Underflow");
    }
    else{
        temp = top;
        top = top ->next;
        free(temp);
    }
    return top;
}

struct node *display(struct node *top){
    struct node *ptr;
    if(top == NULL){
        printf("Stack is Empty!!!");
    }
    else{
        ptr = top;
        while(ptr->next != NULL)
        {
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n",ptr->data);
    }
}

int main(){
    int choice;
    while(1){
        printf("\n**********MAIN MENU**********");
        printf("\n1. Push elements into the stack.");
        printf("\n2. Pop elements of the stack.");
        printf("\n3. Display the elements of the stack.");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid Input!!!Try Again\n");
        }
    }
    return 0;
}