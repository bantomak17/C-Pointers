#include <stdio.h>

int main()
{
	int num = 5;
	void *pv = &num;
	printf("%p\n", pv);
	pv = pv+1;
	printf("%p\n", pv);
	printf("size of pv: %zu\n", sizeof(pv));

	return 0;
}
