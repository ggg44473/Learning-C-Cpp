#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5;
    int *p = NULL;

    p = &a;
    printf("%p\n", p);
    printf("%p\n", p+1);

    int array[5] = {1, 2, 3, 4, 5};
    int *arrayp = NULL;

    arrayp = array;
    printf("%p\n", arrayp);
    printf("%p\n", arrayp+1);
    return 0;
}
