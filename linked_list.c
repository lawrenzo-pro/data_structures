#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node* Node;
//This will help us get the node's length
int len(Node node){
    Node current = node;
    int len = 0;
    while(current != NULL){
        current = current->next;
        len += 1;
    }
    return len;
}

Node new_node(int data){
    Node node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
//Inserting data at the end of the list;
void insert_last(Node node, int data){
    Node current = node;
    while(current->next !=NULL){
        current = current->next;
    }
    current->next =  new_node(data);
}

void print_list(Node node){
    Node current = node;
    while(current != NULL){
        printf("%d,", current->data);
        current = current->next;
    }
    printf("\n");
}
void insert_front(Node *head,int data){
    Node node = new_node(data);
    node->next = *head;
    *head = node;
}
void insert_to_idx(Node *head, int index,int data){
    Node current = *head;
    if(index > len(*head)){
        printf("Invalid index\n");
        return;
    }
    if(index == len(*head)){
        insert_last(*head,data);
        return;
    }
    if(index == 0){
        insert_front(head,data);
        return;
    }
    Node to_be = new_node(data);
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    to_be->next = current->next;
    current->next = to_be;
}
int main(){
    Node head = new_node(5);
    insert_last(head,1);
    insert_last(head,2);
    print_list(head);
    printf("len = %d\n", len(head));
    insert_front(&head,6);
    print_list(head);
    insert_to_idx(&head,4,100);
    print_list(head);
    printf("len = %d\n", len(head));
    insert_to_idx(&head,0,-1);
    print_list(head);
    printf("len = %d\n", len(head));
    return 0;
}