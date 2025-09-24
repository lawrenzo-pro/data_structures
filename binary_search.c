#include <stdio.h>
int binary_search(int value,int array[],int len){
    return 0;
}
int main(){
    int array[] ={0,1,2,3,4,5,6,7,8,9};
    int len = sizeof(array) / sizeof(int);
    int test_1 = 3;
    int test_2 = 7;
    printf("Is %d in the array?%d\n", test_1, binary_search(test_1,array,len));
    printf("Is %d in the array?%d\n",test_2, binary_search(test_2,array,len));
    return 0;
    return 0;
}