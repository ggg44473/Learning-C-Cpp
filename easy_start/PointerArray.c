#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *p[] = {"TECENT", "CAMPUS", "RECRUTING"};
    char **pp[] = {p+2, p+1, p};
    char ***ppp = pp;

    printf("%s\n", **++ppp);
    printf("%s\n", *++*++ppp);
    return 0;
}
