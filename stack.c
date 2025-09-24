#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//LIFO 
struct Stack {
    int *array;
    int capacity;
    int top;
};
typedef struct Stack Stack;
Stack new_stack(int capacity){
    Stack stack;
    stack.capacity = capacity;
    stack.array = malloc(stack.capacity * sizeof(int));
    stack.top = -1;
    return stack;
}
bool is_full(Stack stack){
    return stack.top == stack.capacity - 1;
}
bool is_empty(Stack stack){
    return stack.top == -1;
}
void push(Stack *stack, int data){
    if(is_full(*stack)){
        printf("Stack Full!\n");
        return;
    }
    stack->top += 1;
    stack->array[stack->top] = data;
}
int pop(Stack *stack){
    if(is_empty(*stack)){
        printf("Stack is empty!\n");
        return __INT_MAX__;
    }
    int ret = stack->array[stack->top];
    stack->top -= 1;
    return ret;
}
int peek(Stack stack){
    if(is_empty(stack)){
        printf("Stack is empty!\n");
        return __INT_MAX__;
    }
    int ret = stack.array[stack.top];
    return ret;
}
void print_stack(Stack stack){
    for(int i = 0; i <= stack.top;i++){
        printf("%d,", stack.array[i]);
    }
    printf("\n");
}
int main(){
    Stack stack = new_stack(5);
    int c = pop(&stack); // pop from empty stack
    push(&stack,0);
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    print_stack(stack);
    push(&stack,5); //stack full;
    print_stack(stack);
    int p = pop(&stack);
    int q = peek(stack);
    printf("%d\n", p);
    print_stack(stack);
    printf("%d\n",q);
    print_stack(stack);

    return 0;
}