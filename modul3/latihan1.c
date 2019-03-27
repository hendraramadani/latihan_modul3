#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;

int status;
int nomor;

void* tulis(void *arg)
{
    status = 0;

    FILE *fail,*tulis;
    fail=fopen("baca.txt","r");
    tulis=fopen("salin1.txt","w+");
    char buffer;

    buffer = fgetc(fail); 
    while (buffer != EOF){ 
        fputc(buffer, tulis); 
        buffer = fgetc(fail); 
    } 
  
    fclose(fail);
    fclose(tulis);
    status = 1; //set status
    return NULL;
}

void* baca(void *arg)
{
    while(status != 1)
    {
	//menunggu status ganti 1
    }

    FILE *fail,*tulis;
    fail=fopen("salin1.txt","r");
    tulis=fopen("salin2.txt","w+");
    char buffer;

    buffer = fgetc(fail); 
    while (buffer != EOF){ 
        fputc(buffer, tulis); 
        buffer = fgetc(fail); 
    }

    fclose(fail);
    fclose(tulis);
}


int main(void)
{
    pthread_create(&(tid1), NULL, &tulis, NULL);
    pthread_create(&(tid2), NULL, &baca, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

