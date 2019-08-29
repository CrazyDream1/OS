#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
    printf ("integer: value - %d, size - %d\n", a, sizeof(a));
    printf ("float: value - %f, size - %d\n", b, sizeof(b));
    printf ("double: value - %lf, size - %d\n", c, sizeof(c));
}
