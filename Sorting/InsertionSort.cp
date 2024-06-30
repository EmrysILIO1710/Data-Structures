// time complexity : O(n^2)
// optimized sollution : O(n)
// best case : O(n)

#include <stdio.h>

void insertionSort(int *, int);
void print(int *, int);

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, size);
    print(arr, size);
    return 0;
}

void insertionSort(int *a, int s){
    for(int i = 1; i < s; i++){
        int key = *(a + i);
        int j = i - 1;
        while(j >= 0 && *(a + j) > key){
            *(a + j + 1) = *(a + j);
            j--;
        }
        *(a + j + 1) = key;
    }
}

void print(int *a, int s){
    printf("\nSorted array: \n");
    for(int i = 0; i < s; i++){
        printf("%d\t", *(a + i));
    }
}
