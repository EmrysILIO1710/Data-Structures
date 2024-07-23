#include <stdio.h>

int partition(int *a, int lb, int ub){
    int pivot = *(a + lb);
    int s = lb;
    int e = ub;
    while(s < e){
        while(*(a + s) <= pivot){
            s++;
        }
        while(*(a + e) > pivot){
            e--;
        }
        if(s < e){
            int temp = *(a + s);
            *(a + s) = *(a + e);
            *(a + e) = temp;
        }
    }
    int temp = *(a + e);
    *(a + e) = *(a + lb);
    *(a + lb) = temp;
    return e;
}

void quickSort(int *a, int s, int e){
    if(s < e){
        int p = partition(a, s, e);
        quickSort(a, s, p - 1);
        quickSort(a, p + 1, e);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n-1);

    printf("Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}