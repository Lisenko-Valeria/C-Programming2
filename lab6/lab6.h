#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node* next;
    struct node* level2;
};
typedef struct node node;

node* new_node(int data);
bool search(node* head, node* x);
void print(node* head);
void add_end(node** head, int data);
void add_begining(node** head, int data);