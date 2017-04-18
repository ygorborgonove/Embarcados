#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>

int q;
int s=1;

void *p1(){
int t=0;
	
	while(1){	
		
		if(t != s){	
			printf("%d \n", q);
			t = s;
	
			if(q == 10){
			exit(0);	
			}
		}
	}

}

int main(){
	int i;
   
	pthread_t T1;
	pthread_create(&T1, NULL, &p1, NULL);

	for(i=0; i<10; i++){
		q=i+1;
		s++;
	sleep(1);
	}
    	
    return 0;
}
