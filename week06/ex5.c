#include <stdio.h>
#include <signal.h>
#include <unistd.h> 
#include <stdlib.h>

void F_SIGTERM(){
    printf("SIGTERM - !!!!!\n");
    exit(0);
}

int main() {
    signal(SIGTERM, F_SIGTERM);
    int pid;
    if ((pid = fork()) != 0) {
	sleep(5);
	kill (pid, SIGTERM);
    } else {
      while(1){
	printf("I'm alive\n");
	sleep(1);
      }
    }
    
}
/*
pavlov@pavlov-Inspiron-7577:~/week1$ gcc ex5.c -o ex5
pavlov@pavlov-Inspiron-7577:~/week1$ ./ex5
I'm alive
I'm alive
I'm alive
I'm alive
I'm alive
SIGTERM - !!!!!
pavlov@pavlov-Inspiron-7577:~/week1$ 
*/
