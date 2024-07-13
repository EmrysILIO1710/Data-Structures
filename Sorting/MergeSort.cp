// time complexity : O(n log n)
// optimized sollution : O(n log n)
// best case : O(n log n)

#include <stdio.h>

void mergeSort(int *, int, int); //to divide
void merge(int *, int, int, int); //to merge
void print(int *, int);

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, size);
    print(arr, size);
    return 0;
}

void mergeSort(int *a, int lb, int ub){
    if(lb < ub){
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void merge(int *a, int lb, int mid, int ub){
    int i = lb, j = mid + 1, k = lb;
    int b[ub + 1];
    //comparing and merging
    while(i <= mid && j <= ub){
        if(*(a + i) < *(a + j)){
            b[k] = *(a + i);
            i++;
            k++;
        }
        else{
            b[k] = *(a + j);
            j++;
            k++;
        }
    }
    //if elements are left
    if(i < mid){
        while(i <= mid){
            b[k] = *(a + i);
            i++;
            k++;
        }
    }
    else{
        while(j <= ub){
            b[k] = *(a + j);
            j++;
            k++;
        }
    }
}
    
void print(int *a, int s){
    printf("\nSorted array: \n");
    for(int i = 0; i < s; i++){
        printf("%d\t", *(a + i));
    }
}
