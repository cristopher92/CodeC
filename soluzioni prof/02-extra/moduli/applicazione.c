#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "somma.h"
#include "prodotto.h"

int main(int argc, char *argv[]) {

	if (argc==3) {
		int i=atoi(argv[1]);
		int j=atoi(argv[2]);

		printf("i+j = %d\n", somma(i,j));	
		printf("i*j = %d\n", moltiplica(i,j));
	} else {
		printf("Sono richiesti due argomenti. Ne sono stati inseriti %d\n",argc-1);
	}

	
}
