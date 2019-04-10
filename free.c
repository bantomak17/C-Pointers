#include <stdio.h>
#include <stdlib.h>

void saferFree(void **pp){
	if(pp != NULL && *pp != NULL){
		free(*pp);
		*pp = NULL;
	}
}

#define safeFree(p) saferFree((void **)&(p))

int main()
{
	int *pi ;
	pi = (int *)malloc(sizeof(int));
	*pi = 5;
	printf("Before: %p\n", pi);
	safeFree(pi);
	printf("After: %p\n", pi);
	safeFree(pi);
	return (EXIT_SUCCESS);
}
