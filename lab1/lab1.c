//рабочая версия
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 10000
#define A 301 //max ball

struct student {
    char name[50]; 
    int math; 
    int phy;
    int inf;
    int s;
};

struct student addstudent(char* name, int math, int phy, int inf){
    struct student newstudent;
    strcpy(newstudent.name, name);
    newstudent.math = math;
    newstudent.phy = phy;
    newstudent.inf = inf;
    newstudent.s = math+phy+inf;
    return newstudent;
}

void printStudentInfo(struct student some){
    printf("name %s, math %d, phy %d, inf %d, sum %d\n", some.name, some.math, some.phy, some.inf, some.s);
}

void selection_sort(struct student students[N]){
    for (int i=0; i<N; i++){
        int ind_min=i;
        for (int j=(i+1); j<N; j++){
            if (students[j].s < students[ind_min].s){
                ind_min = j;  
            }
        }
        struct student tmp = students[i];
        students[i] = students[ind_min];
        students[ind_min] = tmp;
    } 
    printf("\n");
    for (int i=0; i<N; i++){
        printStudentInfo(students[i]);
    }
}

void counting_sort(struct student students[]) {
    struct student sorted_students[N];
    int number_of_results[A] = {0}; 

    for (int i=0; i<N; i++){
        number_of_results[students[i].s]++;
    }
    // Изменение count[i] так, чтобы count[i] содержал индекс в выходном массиве
    for (int i=1; i<=300; i++) { //??
        number_of_results[i] += number_of_results[i - 1];
    }
    // Построение выходного массива
    for (int i=N-1; i>=0; i--) {
        sorted_students[number_of_results[students[i].s] - 1] = students[i];
        number_of_results[students[i].s]--;
    }

    for (int i=0; i<N; i++){
        printStudentInfo(sorted_students[i]);
    }
    
}
// требующий слишком много памяти вариант 
/*
void counting_sort(struct student students[N]){
    struct student sorted_stud[A][N] = {0};

    for (int i=0; i<N; i++){
        int ind = 0;
        ind = students[i].s;
        sorted_stud[ind][i]=students[i];   
    }
    for (int i=0; i<A; i++){
        for (int j=0; j<N; j++){
            if (strlen(sorted_stud[i][j].name)!=0) {
                printStudentInfo(sorted_stud[i][j]);
            }
        }
    }
    printf("\n");
}*/

int quicksort_division(struct student students[], int start, int end){
    int n = end-start+1;
    int r = rand()%n+start;
    int from_left = start;
    int from_right = end;
    for (from_right; from_right>=r; from_right--){
        if (students[from_right].s < students[r].s){
            for (from_left; from_left <= r; from_left++){
                if (students[from_left].s >= students[r].s){
                    int tmp = students[from_right].s;
                    students[from_right].s = students[from_left].s;
                    students[from_left].s = tmp;
                    if(from_left==r){
                        r = from_right;
                    }
                    break;
                }
            }
        }
        if (from_right==r){
            for (from_left; from_left <= r; from_left++){
                if ((students[from_left].s >= students[r].s) && (r!=from_left)){
                        int tmp = students[r].s;
                        students[r].s = students[from_left].s;
                        students[from_left].s = tmp;
                        r = from_left;
                        break;
            }}
        }
    }
    return r;
}

void quicksort(struct student students[], int start, int end){
    int r =0;
    if ((end-start)!=0){
        r = quicksort_division(students, start, end);
        if (r>1){
            quicksort(students, 0, r-1);
        }
        if ((end-r)>1){
            quicksort(students, r+1, end);
        }
    }


}

int main(){
    //сlock_t в языке C — тип, для хранения процессорного времени в виде количества циклов процессора, прошедших с начала процесса
    clock_t start = clock();
    struct student students[N]; 
    char* names[] = {"Александр", "Алексей", "Анастасия", "Андрей", "Анна", "Артем", "Борис", "Вадим", "Валентин", "Валерий", "Василий", "Вера", "Вероника", "Виктор", "Виктория", "Владимир", "Владислав", "Галина", "Геннадий", "Георгий", "Глеб", "Григорий", "Даниил", "Дарья", "Денис", "Дмитрий", "Евгений", "Евгения", "Екатерина", "Елена", "Елизавета", "Жанна", "Захар", "Иван", "Игорь", "Илья", "Инна", "Ирина", "Кирилл", "Константин", "Ксения", "Лариса", "Лев", "Леонид", "Лидия", "Любовь", "Людмила", "Макар", "Максим", "Маргарита", "Марина", "Мария", "Мирослава", "Михаил", "Надежда", "Наталья", "Никита", "Николай", "Нина", "Оксана", "Олег", "Ольга", "Павел", "Полина", "Роман", "Руслан", "Светлана", "Семен", "Сергей", "София", "Станислав", "Степан", "Тамара", "Татьяна", "Тимофей", "Тимур", "Ульяна", "Федор", "Эдуард", "Эльвира", "Юлия", "Юрий", "Яна", "Ярослав", "Адель", "Аида", "Алина", "Алиса", "Алла", "Альберт", "Амалия", "Амира", "Анатолий", "Ангелина", "Антонина", "Аркадий", "Арсений", "Артур", "Ася", "Богдан", "Валерия", "Варвара", "Вениамин", "Виталий", "Владилена", "Всеволод", "Гавриил", "Давид", "Демид", "Дина", "Доминика", "Ева", "Егор", "Ефим", "Зоя", "Игнат", "Илларион", "Иринарх", "Камилла", "Карина", "Каролина", "Кира", "Клавдия", "Клим", "Кристина", "Ксенофонт", "Лера", "Лика", "Лукьян", "Майя", "Марк", "Марфа", "Матвей", "Мелания", "Милана", "Милена", "Мирон", "Митрофан", "Назар", "Нелли", "Олеся", "Оскар", "Петр", "Платон", "Раиса", "Рамиль", "Регина", "Рената", "Родион", "Ростислав", "Сабина", "Савва", "Савелий", "Серафим", "Снежана", "Стелла", "Тарас", "Теодор", "Тихон", "Фаина", "Филипп", "Элина", "Эмилия", "Юлиан", "Яков"}; 
    srand(time(NULL));
    for (int i=0; i<N; i++){
        int index = (rand())%165;
        students[i] = addstudent(names[index], rand()%100, rand()%100, rand()%100);
        printStudentInfo(students[i]); 
        //printf("%d ", students[i].s);
    }
    printf("\n");
    //selection_sort(students); 
    counting_sort(students);

    /*quicksort(students, 0, N-1);
    for (int k=0; k<N; k++){
        printf("%d ", students[k].s);
    }
    printf("\n");*/

    clock_t end = clock();
    //CLOCKS_PER_SEC — константа, число тиков в секунду для конкретной машины
    double time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("%f\n", time);
}


