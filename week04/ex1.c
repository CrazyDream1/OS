#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int n;
    n = getpid();
	printf("Hello from parent %d\n", n);
	n = fork();
	if (n == 0) printf("Hello from child %d\n", getpid());
	return 0;
}
