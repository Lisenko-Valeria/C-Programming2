#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

//2
void* child_thread_func() {
    for (int i = 1; i <= 5; i++) {
        printf("Дочерний поток: строка %d\n", i);
    }
    return NULL;
}

//3
struct Thread {
    int id;
    char messages[5][50];
};

typedef struct Thread Thread;
//5
void cleanup_handler(void* arg) {
    Thread* data = (Thread*)arg;
    printf("Поток %d: завершение работы\n", data->id);
}

void* thread_function(void* arg) {
    Thread* data = (Thread*)arg;
    pthread_cleanup_push(cleanup_handler, data);
    for (int i = 0; i < 5; i++) {
        printf("Поток %d: %s\n", data->id, data->messages[i]);
        sleep(1);
    }
    pthread_cleanup_pop(0);
    return NULL;
}

void* sleepsort_thread(void* arg) {
    int x = *((int*)arg);
    sleep(x);
    printf("%d ", x);
    return NULL;
}

/*2
int main() {
    pthread_t child_thread;
    
    if (pthread_create(&child_thread, NULL, child_thread_func, NULL) != 0) {
        perror("Ошибка при создании потока");
        return 1;
    }

    pthread_join(child_thread, NULL);
    
    for (int i = 1; i <= 5; i++) {
        printf("Родительский поток: строка %d\n", i);
    }
}
*/
////////////////////////////////////////////////
/*5
int main() {
    
    pthread_t threads[4];
    Thread data[4];
    
    pthread_t threads[4];
    Thread data[4];
    
    for (int i = 0; i < 4; i++) {
        data[i].id = i + 1;
        for (int j = 0; j < 5; j++) {
            sprintf(data[i].messages[j], "Сообщение %d от потока %d", j+1, i+1);
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, &data[i])) {
            perror("Ошибка при создании потока");
            return 1;
        }
    }

    sleep(2);
    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

}*/
int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = 10;
    pthread_t threads[n];
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        if (pthread_create(&threads[i], NULL, sleepsort_thread, &arr[i])) {
            perror("Ошибка при создании потока");
            return 1;
        }
    }
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
}
