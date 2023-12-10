#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 100
int queue[MAX];
int front = -1, rear = -1;


void enQueue(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    if(rear == MAX -1){
        printf("Queue is full!!!");
    }
    else{
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear++;
        }
        queue[rear] = data;
        printf("\nPush Operation succesfful!!!\n");
    }
}

void deQueue(){
    if(front == -1 || front > rear){
        printf("Stack Underflow!!!");
    }
    else{
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }
        printf("Popped element!!!");
    }
}

void display(){
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\n Elements in the queue are\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("%d\t",queue[i]);  
        }     
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

