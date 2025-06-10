#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#define N 5

struct worker{
    char name[100];
    char phone[11];
    int birth[3];
};

void Print(struct worker A){
    printf("%s %s %d.%d.%d", A.name, A.phone, A.birth[0], A.birth[1], A.birth[2]);
    printf("\n");
}


void SearchName(int n, int x[3], struct worker A[]){
    int f = 0;
    for (int i=0; i<n; i++){
        if (strcmp(A[i].name, x) == 0){
            Print(A[i]);
            f = 1;
        }
    }
    if (f==0) printf("не найден\n");
}

void SearchPhone(int n, int x[3], struct worker A[]){
    int f = 0;
    for (int i=0; i<n; i++){
        if (strcmp(A[i].phone, x) == 0){
            Print(A[i]);
            f = 1;
        }
    }
    if (f==0) printf("не найден\n");
}

void SearchBirth(int n, int x[3], struct worker A[]){
    int f = 0;
    for (int i=0; i<n; i++){
        if (A[i].birth[0] == x[0] && A[i].birth[1] == x[1] && A[i].birth[2] == x[2]){
            Print(A[i]);
            f = 1;
        }
    }
    if (f==0) printf("не найден\n");
}

int main(){
    FILE *file = fopen("/home/valeria/c-prog2/lab5/worker.dat", "wb+");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return(0);
    }

    struct worker workers[5] = {
        {"Анисимов.В.А", "89538617174", {17, 10, 2001}},
        {"Симинов.Р.А", "89138543214", {24, 5, 1998}},
        {"Лебедев.В.И", "89135645980", {4, 12, 1999}},
        {"Лебедев.В.И", "89135645981", {5, 2, 2002}},
        {"Морозов.А.Л", "89137635410", {31, 4, 1995}}
    };

    for (int i=0; i<N; i++){
        fwrite(&workers[i], sizeof(struct worker), 1, file);
    }

    rewind(file);

    struct worker workers2[5] = {0};
    
    for (int i=0; i<N; i++){
        fread(&workers2[i], sizeof(struct worker), 1, file);
    }

    printf("%s", workers2[0].name);

    printf("По какому из полей выполнить поиск? \n 1-ФИО\n 2-номер\n 3-дата рождения\n");
    int field = 0;
    scanf("%d", &field);
    while (field!=1 && field!=2 && field!=3){
        printf("неверное поле\n");
        printf("По какому из полей выполнить поиск? \n 1-ФИО\n 2-номер\n 3-дата рождения\n");
        scanf("%d", &field);
    }


    if (field==1) {
        char a[100] = {0};
        scanf("%s", &a);
        SearchName(N, a, workers2);
    }
    else if (field==2){
        char a[11] = {0};
        scanf("%s", &a);
        SearchPhone(N, a, workers2);
    }
    else {
        int a[3]={0};
        scanf("%d", &a[0]);
        scanf("%d", &a[1]);
        scanf("%d", &a[2]);
        SearchBirth(N, a, workers2);
    }


    fclose(file);
}
