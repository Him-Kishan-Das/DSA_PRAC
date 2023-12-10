#include<stdio.h>
#include<malloc.h>

struct node{
    struct node *next;
    int data;
};

struct node *head=NULL;

struct node *insertAtBeginning(struct node *head){
    struct node *newNode;
    int num;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    newNode -> data = num;
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode -> next = head;
        head = newNode;
    }
    return head;
}


struct node *insertAtEnd(struct node *head){
    struct node *newNode, *ptr;
    int num;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    newNode -> data = num;
    newNode -> next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        ptr = head;
        while(ptr -> next !=NULL){
            ptr = ptr -> next;
        }
        ptr -> next = newNode;
    }
    return head;
}

struct node *display(struct node *head){
    struct node *ptr;
    if(head==NULL){
        printf("List is Empty!!\n");
    }
    else{
        ptr =head;
        while(ptr->next!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr -> next;
        }
        printf("%d\t",ptr->data);
    }
}

struct node *deleteBeginning(struct node *head){
    struct node *temp;
    if(head == NULL){
        printf("Nothing to be Deleted! List is Empty.");
    }
    else{
         temp = head;
         head = temp -> next;
         free(temp);
         printf("Node Delted!");
    }
    return head;
}

struct node *deleteEnd(struct node *head){
    struct node *prePtr, *postPtr;
    if(head == NULL){
        printf("NOthing to be deleted the list is empty!");
    }
    else{
        postPtr = head;
        while(postPtr->next != NULL){
            prePtr = postPtr;
            postPtr = postPtr -> next;
        }
        prePtr -> next = NULL;
        free(postPtr);
    }
}

struct node *deleteSpecific(struct node *head){
    int num;
    struct node *prePtr, *postPtr;
    printf("Enter the data you want to delte: ");
    scanf("%d",&num);
    postPtr = head;
    while(postPtr->data != num){
        prePtr = postPtr;
        postPtr = postPtr -> next;
    }
    if(postPtr->data!= num){
        printf("Specific Data not found in the list.");
    }
    else{
    prePtr -> next = postPtr -> next;
    free(postPtr);
    printf("Specific node delted!");
    }
    
}

struct node *insertAfterSpecific(struct node *head){
    struct node *newNode, *ptr;
    int num, specificNum;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    newNode->data = num;
    printf("Enter the specific number after which you want to insert the data: ");
    scanf("%d",&specificNum);
    ptr = head;
    while(ptr->data!=specificNum){
        ptr = ptr->next;
    }
    newNode->next = ptr -> next;
    ptr->next = newNode;
}

struct node *deleteAfterSpecific(struct node *head){
    struct node *ptr, *temp;
    int specificNum;
    printf("Enter the number after which you want to delete the node: ");
    scanf("%d",&specificNum);
    ptr = head;
    while(ptr->data!=specificNum){
        ptr = ptr -> next;
    }
    temp = ptr -> next;
    ptr -> next = temp -> next;
    free(temp);
}



int main(){
    int choice;
    while(1){
    printf("\n**********MAIN MENU************\n");
    printf("1. Insert Data at the Beginning.\n");
    printf("2. Insert Data at the End.\n");
    printf("3. Display.\n");
    printf("4. Delete At Beginning.\n");
    printf("5. Delete at the End.\n");
    printf("6. Delete Specific data.\n");
    printf("7. Insert After Specific data.\n");
    printf("8. Delete After Specific data.\n");
    printf("9. Exit.\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        head = insertAtBeginning(head);
        break;
    case 2:
        head = insertAtEnd(head);
        break;
    case 3:
        display(head);
        break;
    case 4:
        head = deleteBeginning(head);
        break;
    case 5:
        deleteEnd(head);
        break;
    case 6:
        deleteSpecific(head);
        break;
    case 7:
        insertAfterSpecific(head);
        break;
    case 8:
        deleteAfterSpecific(head);
        break;
    case 9:
        exit(1);
        break;
    default:
        printf("Invalid Input!!!");
        break;
    }
    }
    return 0;
}