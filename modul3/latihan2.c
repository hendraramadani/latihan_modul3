#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>

int prime_arr[1000];
pthread_t tid[50];


struct range{
	int low,high;
};

void* tulis(void* args){
    struct range*extract =(struct range*)args;
    printf("%d %d\n",extract->low,extract->high);

    for(int i =extract->low; i <=extract->high; i++){
        int isPrime = 0;

        for(int j = 2; j <=i/2; j++){
            if(i % j == 0){
                isPrime = i;
                break;
            }
        }

        if(isPrime==0){
            prime_arr[i]= i;
        }
    }
}





int main(void){
    int n;
    int t;
    scanf("%d %d",&n, &t);
    struct range rentang;
    rentang.low=2;
    rentang.high=n/t;

    for(int i=0;i<t-1; i++){
        //printf("> %d %d\n",rentang.low,rentang.high);
        pthread_create(&tid[i], NULL, &tulis,(void *)&rentang);
        pthread_join(tid[i],NULL);
        rentang.low=1+rentang.high;
        rentang.high+=(n/t);
    }

    //ini untuk sisanya.terakhir ,misal 10 3 itu jadi {3 3 4},4 diambil terakhir.
    rentang.high=n;
    pthread_create(&tid[t-1], NULL, &tulis,(void *)&rentang);
    pthread_join(tid[t-1],NULL);

    for(int i=2; i<n; i++){
        if(prime_arr[i]!=0){
            printf("%d\n",prime_arr[i]);
        }
    }
    return 0;
}
