#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

int v[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int valmax = 0;
int i;
int soma1 = 0;
int soma2 = 0;
int soma3 = 0;
int soma4 = 0;

void *p1(){
int i;
	for(i=0; i<4; i++){
		soma1 = v[i] + soma1;
	}

}

void *p2(){
int i;
	for(i=4; i<8; i++){
		soma2 = v[i] + soma2;
		
	}
}

void *p3(){
int i;
	for(i=8; i<12; i++){
		soma3 = v[i] + soma3;
	}
}

void *p4(){
int i;
	for(i=12; i<16; i++){
		soma4 = v[i] + soma4;
	}

}


int main(){
int i;
double med = 0;
		
	for(i=0;i<16; i++){
		if(v[i] > valmax){
			valmax = v[i];
		}
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
	
	med = ((soma1+soma2+soma3+soma4)-valmax)/15;
	printf("A média é: %lf", med);
	
    return 0;
}
