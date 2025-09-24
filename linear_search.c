#include <stdio.h>
//Usinng iteration
int linear_search(int val,int array[],int len){
    for(int i = 0; i < len; i++){
        if(array[i] == val){
            return i;
        }
    }
    return -1;
}
void print_array(int array[],int len){
    for(int i = 0; i < len;i++){
        printf("%d,",array[i]);
    }
    printf("\n");
}
int main(){
    int array[]= {1,2,3,4,5,6};
    int len = sizeof(array) / sizeof(int);
    print_array(array,len);
    int test_1 = 3;
    int test_2 = 7;
    printf("Found %d at %d \n", test_1, linear_search(test_1,array,len));
    printf("Found %d at %d \n", test_2, linear_search(test_2,array,len));
    return 0;
}