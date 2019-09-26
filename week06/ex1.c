#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>

#define NUM 9

int main(int argc, char * argv[]) {
    int p[2];
    char str1[NUM] = "I'a here";
    char str2[NUM] = "";
    printf ("str1 = %s\n", str1);
    printf ("str2 = %s\n", str2);
    pipe(p);
    printf ("Using the pipe...\n");
    write(p[1], str1, NUM);
    read(p[0], str2, NUM);
    printf ("str1 = %s\n", str1);
    printf ("str2 = %s\n", str2);
}
