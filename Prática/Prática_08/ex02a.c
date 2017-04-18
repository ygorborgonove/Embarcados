#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

int main(){
	
long int v[50000];
srand(time(NULL));
int valmax = 0;
int i;


	for(i=0; i<50000; i++){
		v[i] = rand() % 100000;
    	}
	
	for(i=0; i<50000; i++){
		if(v[i] > valmax){
			valmax = v[i];
		}
	}
	printf("o maior valor é: %d \n", valmax);
	
    return 0;
}
