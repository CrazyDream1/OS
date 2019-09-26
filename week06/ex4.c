#include <stdio.h>
#include <signal.h>
#include <unistd.h> 
#include <stdlib.h>

void F_SIGKILL(){
    printf("SIGKILL - !!!!!\n");
    exit(0);
}

void F_SIGSTOP(){
    printf("SIGSTOP - !!!!!\n");
    exit(0);
}

void F_SIGUSR1(){
    printf("SIGUSR1 - !!!!!\n");
    exit(0);
}

int main() {
    signal(SIGKILL, F_SIGKILL);
    signal(SIGSTOP, F_SIGSTOP);
    signal(SIGUSR1, F_SIGUSR1);

    while(1){
	printf("Sleeping...zzz\n");
	sleep(1);
}
}

/*
pavlov@pavlov-Inspiron-7577:~/week1$ gcc ex4.c -o ex4
pavlov@pavlov-Inspiron-7577:~/week1$ ./ex4 &
[1] 17551
pavlov@pavlov-Inspiron-7577:~/week1$ Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
Sleeping...zzz
kill -SIGKILL 17551
pavlov@pavlov-Inspiron-7577:~/week1$ 

---------------------------------------------------------------------
The program caught a signal, launched the corresponding function, not displayed a message, exit program 
*/
