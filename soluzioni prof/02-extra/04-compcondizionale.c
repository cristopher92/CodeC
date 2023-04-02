#include <stdio.h>


int main(int argc, char *argv[]) {
	printf("Test compilazione condizionale\n");

	#if DEBUG
	printf("Facciamo debug!\n");
	#else
	printf("NON facciamo debug!\n");
	#endif

   	return 0;
}
