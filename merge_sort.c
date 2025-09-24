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
void merge(int array[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = array[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            array[k] = leftArr[i];
            i++;
        }
        else {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        array[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}
void merge_sort(int array[],int left, int right){
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}
int main(){
    int array[] = {-10,0,1,2,3,45,-67,0,9,9,8};
    int len =  sizeof(array)/ sizeof(int);
    print_array(array, len);
    merge_sort(array,0,len -1);
    print_array(array,len);
    return 0;
}