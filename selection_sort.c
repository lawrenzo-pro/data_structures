#include <stdio.h>
#include <unistd.h>
void swap(int *a, int *b){
    if(a==b)return;
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
void selection_sort(int array[], int size){
   for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            // Find the minimum element in the unsorted portion
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        swap(&array[min_idx], &array[step]);
        sleep(1);
        print_array(array,size);
    }
}
int main(){
    int array[] = {1,3,4,5,2,1,5,8,100,0,-2};
    int len = sizeof(array) / sizeof(int);
    print_array(array,len);
    selection_sort(array,len);
    print_array(array,len);
    return 0;
}