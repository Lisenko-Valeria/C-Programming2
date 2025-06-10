#include"./lab6.h"

node* new_node(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->level2 = NULL;
    return new;
}

bool search(node* head, node* x){
    while (head != NULL) {
        if (head == x) {
            return true; 
        }
        head = head->next;
    }
    return false; 
}

void print(node* head){
    node* cur = head;
    while (cur){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void add_end(node** head, int data){
    node* new = new_node(data);
    if (*head==NULL){
        *head = new;
        return;
    }
    node* cur = *head;
    while (cur->next!=NULL){
        cur = cur->next;
    }
    cur->next = new;
}

void add_begining(node** head, int data){
    node* new = new_node(data);
    new->next = *head;
    *head = new;
}