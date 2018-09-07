#include <stdio.h>


int demo_read(char [], int [], int);
void demo_write(char [], int [], int);


int main(int argc, char const *argv[])
{
    int a[10];
    int a_count = sizeof(a)/sizeof(int);
    // a passed to other function is int *.

    demo_read("a.bin", a, a_count);
    
    for(int i = 0; i < 10; i++)
    {
        printf("%d, ", a[i]);
        a[i] += 1;
    }
    
    demo_write("a.bin", a, a_count);
    return 0;
}

int demo_read(char fname[], int a[], int a_count)
{
    FILE *f = NULL;

    f = fopen(fname, "rb");
    
    if (f == NULL) {
        printf("File open error.\n");
        return -1;
    }

    fread(a, sizeof(int), a_count, f);

    fclose(f);

    return 0;
}

void demo_write(char fname[], int a[], int a_count)
{
    FILE *f = NULL;

    f = fopen(fname, "wb");
    
    if (f == NULL) {
        printf("File open error.\n");
    }
    
    fwrite(a, sizeof(int), a_count, f);

    fclose(f);
}