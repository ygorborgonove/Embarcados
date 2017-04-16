#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv){
   
	pid_t pid_1;
	pid_t pid_2;
	pid_t pid_3;
    
    	printf("numero do processo pai: %d\n", (int) getpid()); 
	
	system("ps");
    	pid_1 = fork();
    
   	 if(pid_1 == 0){
   	     printf("Eu sou o filho 1 %d\n", (int) getpid()); 
      
    	}
	
   	 else{
	 //pai
	system("ps");
      	  pid_2 = fork();
	
      	  	if(pid_2 == 0){
          	  	printf("Eu sou o filho 2 %d\n", (int) getpid());      
       	 	}	

        	else{
            	   system("ps");
            	   pid_3 = fork();

            		if(pid_3 == 0){
               		 	printf("Eu sou o filho 3 %d\n", (int) getpid());      
           		}
            		else{
                		printf("pai %d\n", (int) getpid());    
            		}    
       	}
    
}
system("ps");
    
    return 0;
}
