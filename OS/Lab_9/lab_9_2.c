#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char sh[6] = "Init"; // Инициализация переменной sh
int n = 100;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* Thread(void* pParams) 
{
    int counter = 0;
    while (1) {
        pthread_mutex_lock(&mutex); // Захватываем мьютекс перед записью в sh
        if (counter % 2) {
            sh[0] = 'H';
            sh[1] = 'e';
            sh[2] = 'l';
            sh[3] = 'l';
            sh[4] = '0';
            sh[5] = '\0';
        } else {
            sh[0] = 'B';
            sh[1] = 'y';
            sh[2] = 'e';
            sh[3] = '_';
            sh[4] = 'u';
            sh[5] = '\0';
        }
        counter++;
        pthread_mutex_unlock(&mutex); // Освобождаем мьютекс после записи в sh
        usleep(100000); // Небольшая задержка для предотвращения гонки
    }
    return NULL;
}

int main(void) 
{
    int t = 10;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &Thread, NULL);
    
    while (t--) {
        pthread_mutex_lock(&mutex); // Захватываем мьютекс перед чтением sh
        printf("%s\n", sh);
        pthread_mutex_unlock(&mutex); // Освобождаем мьютекс после чтения sh
        usleep(500000); // Небольшая задержка между чтениями
    }
    
    // Завершение потока (необходимо добавить механизм завершения потока)
    pthread_cancel(thread_id);
    pthread_join(thread_id, NULL);
    
    return 0;
}