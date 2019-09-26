#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void F(){
	printf("Program will be interrupted");
	exit(0);
}

int main(int argc, char * argv[]) {
   signal(SIGINT, F);
}
