#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(){
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    if(top == MAX - 1){
        printf("Stack Overflow!!!");
    }
    else{
        stack[++top] = value;
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow!!!");
    }
    else{
        stack[top--];
        printf("Popped the element");
    }
}

void display(){
    if(top == -1){
        printf("Stack is Empty.");
    }
    else{
        printf("The elements in the stack is: ");
        for(int i = 0; i<=top; i++){
            printf("%d\t",stack[i]);
        }
        printf("\n");
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
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid Input!! Try Again\n");
        }
    }
    return 0;
}

