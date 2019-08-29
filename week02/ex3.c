#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n;
    sscanf(argv[1], "%d", &n);
    for (int k = 1; k < n + 1; k++){
        for (int i = k; i < n; i++) {
            printf(" ");
        }
        for (int j = 0; j < (k - 1) * 2 + 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
