#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int *array;
    int capacity;
    int no_elements;
};
typedef struct Queue Queue; //Creating a nick_name for struct Queue
Queue new_queue(int capacity){
    Queue queue;
    queue.array = malloc(sizeof(int) * capacity); // allocating our array to the heap //4 
    queue.capacity = capacity;
    queue.no_elements = 0;
    return queue;
}
void enqueue(Queue *queue,int data){
    if(queue->no_elements >= queue->capacity){
        printf("The queue is full!\n");
        return;
    }
    queue->array[queue->no_elements] = data;
    queue->no_elements += 1;
}
void dequeue(Queue *queue){
    if(queue->no_elements <= 0){
        printf("Queue is empty!\n");
        return;
    }
    for(int i = 1; i < queue->no_elements;i++){
        queue->array[i-1] = queue->array[i]; //removes an element
    }
    queue->capacity -= 1; //3
}
int front(Queue queue){
    if(queue.no_elements <= 0){
        printf("Queue is empty!");
        return EXIT_FAILURE;
    }
    return queue.array[0];
}
int back(Queue queue){
    if(queue.no_elements <= 0){
        perror("Queue is empty!\n");
        return EXIT_FAILURE;
    }
    return queue.array[queue.no_elements - 1];
}
void print_front_back(Queue q){
    printf("Front = %d, back=%d\n",front(q),back(q));
}
int main(){
    Queue q = new_queue(5);
    dequeue(&q);//this is also illegal.
    enqueue(&q,0);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);//this exceeds the capacity
    print_front_back(q);
    dequeue(&q);
    print_front_back(q);
    return 0;
}