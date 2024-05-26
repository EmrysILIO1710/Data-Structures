#include <stdio.h>

void sort(int *arr, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int binarySearch(int *arr, int len, int val){
    int flag = -1;
    int left = 0;
    int right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(*(arr + mid) == val){
            flag = mid;
            break;
        }
        else if(*(arr + mid) > val){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return flag;
}

int main(){
    int arr[5];
    int val;
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    scanf("\n%d", &val);
    sort(arr, 5);
    int result = binarySearch(arr, 5, val);
    printf("\n\n%d", result);
}