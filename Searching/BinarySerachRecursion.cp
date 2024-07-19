//binary search using recursion
#include <stdio.h>

int binarySearch(int *a, int left, int right, int val){
    if(left <= right){ 
        int mid = (left + right) / 2;
        if(*(a + mid) == val){
            return mid;
        }
        else if(*(a + mid) > val){
            return binarySearch(a, left, mid - 1, val);
        }
        else{
            return binarySearch(a, mid + 1, right, val);
        }
    }
    else{
        return -1; // Return -1 if the value is not found
    }
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int val = 3;
    int res = binarySearch(a, 0, 4, val);
    printf("%d", res);
}