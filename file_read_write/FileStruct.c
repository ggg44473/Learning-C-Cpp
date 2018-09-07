#include <stdio.h>
#include <stdlib.h>

int demo_read();
void demo_write();

struct _Coord {
    float x;
    float y;
};
typedef struct _Coord Coord;

int main(int argc, char const *argv[])
{
    Coord points[10];
    int p_count;
    int isOpen;

    p_count = sizeof(points)/sizeof(Coord);
    isOpen = demo_read("struct.bin", points, p_count);

    if (isOpen == -1) {    
        for(int i = 0; i < p_count; i++)
        {
            points[i].x = i+i;
            points[i].y = i*i;
            printf("(%f,%f)\t", points[i].x, points[i].y );
        }   
    } else {
        for(int i = 0; i < p_count; i++)
        {
            printf("(%f,%f)\t", points[i].x, points[i].y );
            points[i].y +=1;
        }
    }
    
    demo_write("struct.bin", points, p_count);

    return 0;
}

int demo_read(char fname[], Coord a[], int a_count)
{
    FILE *f = NULL;

    f = fopen(fname, "rb");
    
    if (f == NULL) {
        printf("File open error.\n");
        return -1;
    }

    fread(a, sizeof(Coord), a_count, f);

    fclose(f);

    return 0;
}

void demo_write(char fname[], Coord a[], int a_count)
{
    FILE *f = NULL;

    f = fopen(fname, "wb");
    
    if (f == NULL) {
        printf("File open error.\n");
    }
    
    fwrite(a, sizeof(Coord), a_count, f);

    fclose(f);
}