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
int partition(int array[], int low, int high){
    int pivot = array[low];
    int i = low;
    int j = high;
    while(i < j){
        //getting the first element greater than the pivot(from the beginning)
        while(array[i] <= pivot && i <= high -1){
            i++;
        }
        //getting the first element smaller than the pivot(from end)
         while (array[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[low], &array[j]);
    return j;
}
void quick_sort(int array[],int low,int high){
    //The if statement prevents infinite recursion
    if(low < high){
        int part = partition(array,low,high);
        quick_sort(array,low,part - 1);
        quick_sort(array, part + 1, high);
    }
}
int main(){
    int array[] = { 1,2,3,-7,-9,12,13,56,12};
    int len = sizeof(array) / sizeof(int);
    print_array(array,len);
    quick_sort(array,0,len -1);
    print_array(array,len);
    return 0;
}