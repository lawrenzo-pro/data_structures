#include <stdio.h>
#include <unistd.h>
void swap(int *a, int *b){
    if(a==b)return;
    *a ^= *b; // just believe that this works..
    *b ^= *a; // we are doing an XOR btw;
    *a ^= *b;
}
void print_array(int array[],int len){
    for(int i = 0; i < len;i++){
        printf("%d,",array[i]);
    }
    printf("\n");
}
void exchange_sort(int array[],int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if(array[i] > array[j]){
                swap(&array[i],&array[j]);
            }
            print_array(array,len);
            sleep(1);
        }
    }

}
int main(){
    int array[] = {1,3,4,5,2,1,5,8,100,0,-2};
    int len = sizeof(array) / sizeof(len);
    print_array(array,len);
    exchange_sort(array,len);
    print_array(array,len);
    return 0;
}