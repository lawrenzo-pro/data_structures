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
void merge_sort(int array[],int len){

}
int main(){
    int array[] = {-10,0,1,2,3,45,-67,0,9,9,8};
    int len =  sizeof(array)/ sizeof(int);
    print_array(array, len);
    merge_sort(array,len);
    print_array(array,len);
    return 0;
}