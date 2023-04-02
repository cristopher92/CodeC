#include <stdio.h>

/*
provare a compilare con le opzioni 
-std=c89
-Wall
-Wpedantic
*/



int main(int argc, char *argv[]) {
	int i;
	int a=9;

	printf("Test opzioni di compilazione\n");

	

	for(i=0;i<5;i++) {
		printf("%d\n",i+a);
	}

	
   	return 0;
}
