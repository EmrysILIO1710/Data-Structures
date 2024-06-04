#include <stdio.h>

void selectionSort(int *, int);
void display(int *, int);

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, size);
    display(arr, size);
}

void selectionSort(int *a, int s){
    for(int i = 0; i < s - 1; i++){
        int min = *(a + i);
        int min_ind = i;
        for(int j = i + 1; j < s; j++){
            if(*(a + j) < min){
                min = *(a + j);
                min_ind = j;
            }
        }
        if(min_ind != i){
            int temp = *(a + i);
            *(a + i) = *(a + min_ind);
            *(a + min_ind) = temp;
        }
    }
}

void display(int *a, int s){
    printf("Sorted array: \n");
    for(int i = 0; i < s; i++){
        printf("%d\t", *(a + i));
    }
}