#include <stdio.h>
#include <stdbool.h>
int recursive_linear_search(int value, int array[],int len){
    //these makes sure the function stops;
    if(len == 0){
        return -1;
    }
    if(array[len-1] == value){
        return len - 1 ;
    }
    //recursive call
    return recursive_linear_search(value,array,len -1); //6..5..4...3..2..1..0.
}
int main(){
    int array[] = {9,8,7,2,1,2,3}; //7 
    int len = sizeof(array) / sizeof(int);
    int test_1 = 4;
    int test_2 = 9;
    printf("Found %d at %d\n", test_1, recursive_linear_search(test_1,array,len));
    printf("Found %d at %d\n",test_2, recursive_linear_search(test_2,array,len));
    return 0;
}