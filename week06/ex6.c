#include <stdio.h>
#include <signal.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int status = 0;

int main() {
    printf("Program starts...\n");
    int pid1;
    int p[2];
    pipe(p);
    if ((pid1 = fork()) != 0) {
	int pid2;
	if ((pid2 = fork()) == 0) {
	    printf("Hi from child 2!\n");
	    while (1){}
	} else {
	    char *pid2c = itoa(pid2);
	    write(p[1], pid2c, 10);
	    waitpid(pid2, &status, 0);
	    printf("Something with childs\n");
	}
    } else {
	printf("Hi from child 1!\n");
	sleep(7);
	int pid2;
	char pid2c[10];
	read(p[0], pid2c, 10);
	pid2 = atol(pid2c);
	kill (pid2, SIGSTOP);
	printf("Child 1 kill child 2\n");
    }
}

