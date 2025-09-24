#include <stdio.h>
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
    }
}
int main(){
    int array[] = {1,2,3,-1,-2,-3,0,1,2,4,-90,90,-10,12};
    int len = sizeof(array) / sizeof(int);
    print_array(array,len);
    selection_sort(array,len);
    print_array(array,len);
    return 0;
}