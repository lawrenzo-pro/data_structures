#include <stdio.h>
#include <stdlib.h>

// N -> node -> node-> node ->end
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node* Node;
//This will help us get the list's length
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
    Node node = malloc(sizeof(struct Node)); //reserves 
    node->data = data;
    node->next = NULL;
    return node;
}
//Inserting data at the end of the list;
void insert_last(Node node, int data){
    Node current = node;
    //takes us to last element
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
    // head->list
    Node node = new_node(data);
    //null->node->null
    node->next = *head;
    //node->head;
    *head = node;
    //node->head->list
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
    //next node list, until element before index
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    //current->next
    //tobe->null
    to_be->next = current->next;
    //to_be->next
    current->next = to_be;
    //current->to_be->next-> ....
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
    insert_to_idx(&head,3,3);
    print_list(head);
    free(head);
    return 0;
}