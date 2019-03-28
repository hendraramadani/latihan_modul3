#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#define MSGSIZE 40
char* msg1 = "ls ~/modul3/files";
char* msg2 = "head -3"; 
char* msg3 = "tail -1"; 

int main() 
{ 
    char inbuf[MSGSIZE];
    char arg[40];
    int p[2], i; 
  
    if (pipe(p) < 0) 
        exit(1); 
  
    /* continued */
    /* write pipe */
  
    	write(p[1], msg1, MSGSIZE);  
	write(p[1], msg2, MSGSIZE); 
	write(p[1], msg3, MSGSIZE); 
  	strcpy(arg,"");
	for (i = 0; i < 3; i++) { 
		/* read pipe */
		read(p[0], inbuf, MSGSIZE);
		//printf("%s",inbuf);
		strcat(arg,inbuf);	
		if(i!=2){
			strcat(arg,"|");			
		}
		
	} 
	system(arg);
	//printf("%s",arg);
    return 0; 
} 
