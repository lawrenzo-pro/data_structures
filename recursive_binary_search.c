#include <stdio.h>
int recursive_binary_search(int value,int low,int high, int array[],int len){
    if (high >= low) {
        int mid = low + (high - low) / 2;
        printf("%d, %d , %d  \n", mid,low, high);
        if (array[mid] == value)
            return mid;
        if (array[mid] > value)
            return recursive_binary_search(value,low,mid-1,array,len);
        return recursive_binary_search(value, mid + 1, high, array,len);
    }
    return -1;
}
int main(){
    int array[] ={0,1,2,3,4,5,6,7,8,9};
    int len = sizeof(array) / sizeof(int);
    int test_1 = 3;
    int test_2 = 17;
    printf("Found %d at %d\n", test_1, recursive_binary_search(test_1,0,len-1,array,len));
    printf("Found %d at %d\n",test_2, recursive_binary_search(test_2,0,len-1,array,len));
    return 0;
}