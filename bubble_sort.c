#include <stdio.h>
#include <stdbool.h>

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
void bubble_sort(int array[],int len){
   for(int i = 0; i < len -1 ; i++){
    bool swapped = false;
    for(int j = 0; j < len - i - 1; j++){
        if(array[j] > array[j+1]){
            swap(&array[j],&array[j+1]);
            swapped = true;
        }
    }
    if (swapped == false) {
            break;
    }
   }
}
int main(){
    int array[] = { 1,2,9,10,11,2,11,34,3, -100};
    int len = sizeof(array) / sizeof(int);
    print_array(array,len);
    bubble_sort(array,len);
    print_array(array,len);
    return 0;
}