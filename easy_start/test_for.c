#include <stdio.h>
int main()
{
	for (int i=0; i<10; i++) {
		printf("[%d]\n", i);
	}
	//printf("%d", i);
	//'i' undeclared 因為for做完就沒了
	
	int i;
	printf("%d\n", i);
	//這個會建立for自己的i
	for (int i=0; i<10; i++) {
		printf("[%d]\n", i);
	}
	printf("%d\n", i); // i = 0
	
	int i;
	printf("%d\n", i);
	//這個會取用外面i
	for (i=0; i<10; i++) {
		printf("[%d]\n", i);
	}
	printf("%d\n", i); //i = 10
	
	
	
    return 0;
}