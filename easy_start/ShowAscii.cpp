#include <stdio.h>

int main(int argc, char *argv[]) {

	char c;
	int d;

	printf("We have %d arguments:\n", argc);

	for (int i = 0; i < argc; ++i) {
		c = argv[i][0];
		d = c;
		printf("[%d] %c %d %X \n", i, c, d, d);
		//printf("[%d] %s \n", i, argv[i]);
	}
	return 0;
}