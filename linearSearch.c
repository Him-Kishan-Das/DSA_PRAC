#include<stdio.h>

int main(){
    int arr[] = {21, 4, 65, 12, 76, 13, 88, 45};
    int search;
    // int arrSize = sizeof(arr);
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("The array elements are: ");
    for(int i =0; i<size; i++){
        printf("%d\t",arr[i]);
    }
    printf("\nEnter the value you want to search: ");
    scanf("%d",&search);
    for(int i = 0; i<size; i++){
        if(arr[i] == search){
            printf("Elements %d is present at index: %d",arr[i], i);
        }
    }
    return 0;
}