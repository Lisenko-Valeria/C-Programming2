//free
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node* next;
    struct node* level2;
};
typedef struct node node;

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

int main(){
    node* head = NULL;
    node* head2 = NULL;
    int n, k;
    printf("введите n k ");
    scanf("%d %d", &n, &k);
    int s[k];
    printf("введите числа ");
    for (int i=0; ((i<=n) || (i<=k)); i++){ //заполнение
        int a;
        if (i<n){
            scanf("%d", &a);
            add_end(&head, a);
        }
        if (i<k) {
            scanf("%d", &a);
            add_begining(&head2, a);}
    }
    node* cur=head->next;
    node* cur2=head2;
    node* level2_stopper=head2;
    while (level2_stopper->next != NULL){
        level2_stopper = level2_stopper->next;
    } 

    while (cur){
        cur2=head2;
        while (cur2->next != level2_stopper){
            cur2 = cur2->next;
        }
        cur->level2 = cur2; 
        if (cur2==head2) break;
        if (cur->next == NULL) break;
        cur = cur->next;
        level2_stopper = cur2;
    }
    //cur2=head2;
    while (cur2->next !=NULL){
        cur2 = cur2->next;
    }
    while (cur->next !=NULL){
        cur = cur->next;
    }
    cur->next = cur2;
    cur2->level2 = head;

    

    node* curr=head;
    printf("%d", head->data);
    int f=1;
    while (1){
        printf("\nвыберите 2,4,6 или 8 для прохода по списку, или 0 для выхода ");
        int a;
        scanf("%d", &a);
        switch (a){
            case 2:
                if(!(search(head2, curr)) && curr->level2!=NULL){
                    printf("%d ", curr->level2->data);
                    curr = curr->level2;
                }
                else {
                    printf("в этом направлении нельзя переместиться. Хотите вернуться в начало? y/n");
                    char b;
                    scanf("%s", &b);
                    if (b=='y'){
                        curr=head;
                    }
                    printf("%d", curr->data);
                }
                break;
            case 4:
                if(search(head2, curr) && (curr->level2)==NULL){
                    printf("%d ", curr->next->data);
                    curr = curr->next;
                }
                else {
                    printf("в этом направлении нельзя переместиться. Хотите вернуться в начало? y/n");
                    char b;
                    scanf("%s", &b);
                    if (b=='y'){
                        curr=head;
                    }
                    printf("%d", curr->data);
                }
                break;
            case 6:
                if (!(search(head2, curr))) {
                    printf("%d ", curr->next->data);
                    curr = curr->next;
                }
                else {
                    printf("в этом направлении нельзя переместиться. Хотите вернуться в начало? y/n");
                    char b;
                    scanf("%s", &b);
                    if (b=='y'){
                        curr=head;
                    }
                    printf("%d", curr->data);
                }
                break;
            case 8:
                if (curr->level2==head) {
                    printf("%d ", curr->level2->data);
                    curr = curr->level2;
                }
                else {
                    printf("в этом направлении нельзя переместиться. Хотите вернуться в начало? y/n ");
                    char b;
                    scanf("%s", &b);
                    if (b=='y'){
                        curr=head;
                    }
                    printf("%d", curr->data);
                }
                break;
            case 0:
                f=0;
        }
        if (f==0) break;
  
    }
}

