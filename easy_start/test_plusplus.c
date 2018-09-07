#include <stdio.h>
int main()
{
	int d = 0;
	d = d++;
	printf("%d \n", d);
	
	int e = 0;
	e = ++e;
	printf("%d \n", e);
    
    return 0;
}