#include <stdio.h>
void print_array(int array[],int len){
    for(int i = 0; i < len;i++){
        printf("%d,",array[i]);
    }
    printf("\n");
}
void insertion_sort(int array[],int len){
    for(int i = 0;i < len; i++){
        int key = array[i];
        int j = i - 1; // -1
        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
        print_array(array,len);
    }
}
int main(){
    int array[] = {1,3,4,5,2,1,5,8,100,0,-2};
    int len = sizeof(array) / sizeof(int);
    print_array(array,len);
    insertion_sort(array,len);
    print_array(array,len);
    return 0;
}