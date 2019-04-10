#include <stdio.h>

int main()
{
	int num;
	intptr_t *pi = &num;
	printf("Value of pi: %p\n", pi);
	void *pv = pi;
	pi = (intptr_t *)pv;
	printf("Value of pi: %p\n", pi);

	return 0;
}
