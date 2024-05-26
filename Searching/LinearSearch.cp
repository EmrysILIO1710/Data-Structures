#include <stdio.h>

int linearSearch(int *arr, int len, int val){
    int flag = -1;
    for(int i = 0; i < len; i++){
        if(*(arr + i) == val){
            flag = i;
            break;
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
    int result = linearSearch(arr, 5, val);
    printf("\n\n%d", result);
}