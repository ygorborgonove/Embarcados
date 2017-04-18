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
	char perg1f[100];
	char perg2f[100];
	char perg1p[100];
	char perg2p[100];
	strcpy(perg1f, "Pai, qual a verdadeira essência da sabedoria?");
	strcpy(perg2f, "Mas até uma criança de três anos sabe disso!");
	strcpy(perg1p, "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.");
	strcpy(perg2p, "Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
	
	pipe(fd);	
	p1 = fork();
	
//filho
if(p1 == 0){
	
	if(write(fd[1], perg1f, sizeof(perg1f)) < 0){
		printf("erro na escritura");
	}
	sleep(1);

	if(read(fd[0], perg1p, sizeof(perg1p)) < 0){
		printf("erro na escritura");
	}
	else{
		printf("PAI: %s \n", perg1p);
	
	}
	sleep(1);

	if(write(fd[1], perg2f, sizeof(perg2f)) < 0){
		printf("erro na escritura");
	}
	sleep(1);

	if(read(fd[0], perg2p, sizeof(perg2p)) < 0){
		printf("erro na escritura");
	}
	else{
		printf("PAI: %s \n", perg2p);
	
	}

	sleep(1);
	exit(0);

}
//pai
else{

	if(read(fd[0], perg1f, sizeof(perg1f)) < 0){
		printf("erro na leitura");
	}
	else{
		printf("FILHO: %s \n", perg1f);
	}
	sleep(1);

	if(write(fd[1], perg1p, sizeof(perg1p)) < 0){
		printf("erro na escrita");
	}
	sleep(1);
	
	if(read(fd[0], perg2f, sizeof(perg2f)) < 0){
		printf("erro na leitura");
	}
	else{
		printf("FILHO: %s \n", perg2f);
	}
	sleep(1);

	if(write(fd[1], perg2p, sizeof(perg2p)) < 0){
		printf("erro na escrita");
	}

	sleep(1);
	exit(0);
}
    	
    return 0;
}
