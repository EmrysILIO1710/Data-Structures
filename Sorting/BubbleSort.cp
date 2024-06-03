#include <stdio.h>

void bubbleSort(int *, int);
void print(int *, int);

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, size);
    print(arr, size);
}

void bubbleSort(int *a, int s){
    for(int i = 0; i < s - 1; i++){
        int flag = 0;
        for(int j = 0; j < s - i - 1; j++){
            if(*(a + j) > *(a + j + 1)){
                int temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
}

void print(int *a, int s){
    printf("\nSorted array: \n");
    for(int i = 0; i < s; i++){
        printf("%d\t", *(a + i));
    }
}
