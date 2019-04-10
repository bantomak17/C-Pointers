#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[50] = {0,};
	int i =0;
	int j = 0;
	int len = 0;
	char *reverse = NULL;
	printf("Input string:");
	scanf("%s\n", str);
	len = strlen(str);
	printf("%d\n", len);
	reverse = (char *)malloc(sizeof(len) + 1);
	
	for(i = len-1, j = 0; i >= 0; i--, j++)
	{
		reverse[j] = str[i];
	}
	reverse[j] = '\0';
	printf("[%s]\n", reverse);
	return 0 ;
}
