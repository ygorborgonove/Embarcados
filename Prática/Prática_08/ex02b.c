#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

long int v[50000];
int valmax = 0;
int i;
int v_aux[3] = {0, 0, 0, 0};

void *p1(){
int i;
	for(i=0; i<12500; i++){
		if(v[i] > v_aux[0]){
			v_aux[0] = v[i];
		}
	}

}

void *p2(){
int i;
	for(i=12500; i<25000; i++){
		if(v[i] > v_aux[1]){
			v_aux[1] = v[i];
		}
	}
}

void *p3(){
int i;
	for(i=25000; i<37500; i++){
		if(v[i] > v_aux[2]){
			v_aux[2] = v[i];
		}
	}
}

void *p4(){
int i;
	for(i=37500; i<50000; i++){
		if(v[i] > v_aux[3]){
			v_aux[3] = v[i];
		}
	}

}


int main(){
int i;
srand(time(NULL));
	
	for(i=0; i<50000; i++){
		v[i] = rand() % 100000;
    	}

	pthread_t T1;
	pthread_t T2;
	pthread_t T3;
	pthread_t T4;
	pthread_create(&T1, NULL, &p1, NULL);
	pthread_create(&T2, NULL, &p2, NULL);
	pthread_create(&T3, NULL, &p3, NULL);
	pthread_create(&T4, NULL, &p4, NULL);
	pthread_join(T1, NULL);
	pthread_join(T2, NULL);
	pthread_join(T3, NULL);
	pthread_join(T4, NULL);

	for(i=0;i<=3; i++){
		if(v_aux[i] > valmax){
			valmax = v_aux[i];
		}
	}

	printf("o maior valor é: %d \n", valmax);
	
	
	
    return 0;
}
