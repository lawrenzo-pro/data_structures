#include <stdio.h>
void swap(int *a, int *b){
    *a ^= *b;//don't mind the bitwise operation
    *b ^= *a;
    *a ^= *b;
}
void print_array(int array[],int len){
    for(int i = 0; i < len;i++){
        printf("%d,",array[i]);
    }
    printf("\n");
}
void selection_sort(int array[], int len){
    
}
int main(){
    int array[] = {1,2,3,-1,-2,-3,0,-0,1,2,4,-90,90,-10,12};
    int len = sizeof(array) / sizeof(int);
    print_array(array,len);

    return 0;
}