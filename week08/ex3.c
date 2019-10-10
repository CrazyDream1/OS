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
        sleep(1);
    }
    for (int i = 0; i < 10; i++)
        free(a[i]);
}
/*
pavlov@pavlov-Inspiron-7577:~/week1$ ./ex2&
[1] 4668
pavlov@pavlov-Inspiron-7577:~/week1$ top -p4668

top - 23:07:15 up  1:11,  1 user,  load average: 0,30, 0,38, 0,42
Tasks:   1 total,   0 running,   1 sleeping,   0 stopped,   0 zombie
%Cpu(s):  1,9 us,  0,7 sy,  0,0 ni, 96,9 id,  0,0 wa,  0,0 hi,  0,5 si,  0,0 st
КиБ Mem : 16284080 total, 12473896 free,  1932080 used,  1878104 buff/cache
КиБ Swap: 16454652 total, 16454652 free,        0 used. 13487064 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 4668 pavlov    20   0   96700  93304   1136 S   1,0  0,6   0:00.06 ex2
















[1]+  Завершён        ./ex2
*/
