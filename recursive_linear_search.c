#include <stdio.h>
#include <stdbool.h>
int recursive_linear_search(int value, int array[],int len){
    if(len == 0){
        return -1;
    }
    if(array[len-1] == value){
        return array[len - 1];
    }
    return recursive_linear_search(value,array,len -1);
}
int main(){
    int array[] = {9,8,7,2,1,2,3};
    int len = sizeof(array) / sizeof(int);
    int test_1 = 0;
    int test_2 = 9;
    printf("Is %d in the array?%d\n", test_1, recursive_linear_search(test_1,array,len));
    printf("Is %d in the array?%d\n",test_2, recursive_linear_search(test_2,array,len));
    return 0;
}