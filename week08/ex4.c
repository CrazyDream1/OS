#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    int *a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(1024 * 1024 * 10);
        memset(a[i], 0, 1024 * 1024 * 10);
	struct rusage *r; 
	int f = getrusage(RUSAGE_SELF, r);
	if (f == 0) printf("%ld", r -> ru_idrss);
        sleep(1);
    }
    for (int i = 0; i < 10; i++)
        free(a[i]);
}
/*
pavlov@pavlov-Inspiron-7577:~/week1$ ./ex5
Ошибка сегментирования (стек памяти сброшен на диск)
*/
//I don't know why it is not work.
