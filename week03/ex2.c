#include <stdio.h>

void bubble_sort(int* a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1]) {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
}

int main()
{
    int k[5] = {5,18,15,4,1};
    bubble_sort(k, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", k[i]);
}
