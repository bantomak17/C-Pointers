#include <stdio.h>
#include <stdlib.h>


void exceptionExample(){
	int *pi = NULL;
	__try{
		pi = (int *)malloc(sizeof(int));
		*pi = 5;
		printf("%d\n", *pi);
	}
	__finally{
		free(pi);
	}
}
int main()
{
	char *pc = (char *) malloc(6);
	for(int i = 0; i< 8; i++){
		pc[i] = 'c'; //same with *(pc+i) = 'c';
		printf("[%c]\n", pc[i]);
		printf("%p\n", &pc[i]);
	}

	char *chunk;
	while(1){
		chunk = (char *) malloc(10000000000000);
		printf("Allocating\n");
	}
	
	return 0;
}
