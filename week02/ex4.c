#include <stdio.h>
void my_swap(int *a, int* b)
{
    int t = *b;
    *b = *a;
    *a = t;
}

int main() {
	printf("Enter two integers:\n");
	int a, b;
	scanf("%d %d", &a, &b);
	my_swap(&a, &b);
	printf ("After the swap:\n%d - %d\n", a, b);
}
