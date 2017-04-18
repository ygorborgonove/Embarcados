#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

int main(){
   
	pid_t p1;
	int fd[2];
	int i;
	int q;
	
	pipe(fd);	
	p1 = fork();
	
//filho le os numeros

if(p1 == 0){
	int q;
	int i;
	
	for(i=0; i<10; i++){
		
		if(read(fd[0], &q, sizeof(int)) < 0){
			printf("erro na leitura \n");
		}
			
		else{
			printf("%d \n", q);
		}
	sleep(1);
	}

printf("filho se preparando para desligar \n");
sleep(1);
}

else{

int d;
int q;

	for(d=0; d<10; d++){
		q = d+1;
		if(write(fd[1], &q, sizeof(int)) < 0){
			printf("erro na escrita");
		}	

		sleep(1);
    	}

	printf("Vou terminar a minha execução, cambio desligo \n");
	sleep(1);
}
    	
    return 0;
}
