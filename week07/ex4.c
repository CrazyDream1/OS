#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

#define NUM 9

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

void* array_change_size(void* array, size_t new_size)
{
    int old_size = _msize(array);
    void* new_array = malloc(new_size);
    for (int i = 0; i < min(old_size, new_size); i++)
        ((char*)new_array)[i] = ((char*)array)[i];
    return new_array;
}

int main(int argc, char * argv[]) {

}
