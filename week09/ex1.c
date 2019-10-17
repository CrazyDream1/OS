#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a[100][2];
int n;

int find(int t) {
    for (int i = 0; i < n; i++) {
        if (a[i][0] == t) return 1;
    }
    return 0;
}

void replace(int t) {
    int m = 1e9, mi = 0;
    for (int i = 0; i < n; i++) {
        if (m > a[i][1]) {
            m = a[i][1];
            mi = i;
        }
        if (a[i][0] == 0)
        {
            m = -1;
            mi = i;
        }
    }
    a[mi][0] = t;
    a[mi][1] = 1073741824;
}

void tick(){
    for (int i = 0; i < n; i++)
        a[i][1] = a[i][1] / 2;
}

int main(int argc, char * argv[]) {
    scanf("%d", &n);
    FILE* in = fopen("Lab 09 input.txt", "r");
    int hit = 0, miss = 0;
    int k, t;
    while ((k = fscanf(in, "%d", &t)) == 1){
        if (find(t) == 0) {
            miss++;
            replace(t);
            tick();
        } else {
            hit++;
            tick();
        }
    }
    printf("Hit/Miss - rate: %d / %d = %f", hit, miss, (double)hit / miss);
    fclose(in);
}
/*
Input: 10
Output: Hit/Miss - rate: 10 / 990 = 0.010101
*/
/*
Input: 50
Output: Hit/Miss - rate: 54 / 946 = 0.057082
*/
/*
Input: 100
Output: Hit/Miss - rate: 94 / 906 = 0.103753
*/
