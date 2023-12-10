// Bubble Sort 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n){
    int temp;
    for(int i = 0; i<n-1; i++){
        for(int j =0; j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted list is : ");
    for(int i =0; i<n; i++){
        printf("%d\t",arr[i]);
    }   
}

int main(){
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    return 0;
}