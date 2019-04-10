#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(char *phrase)
{
	char *old = phrase;
	char *new = phrase;

	while(*old == ' '){
		old++;
	}

	while(*old){
		*(new++) = *(old++);
	}
	*new = 0;
	return (char *)realloc(phrase, strlen(phrase)+1);
}
char *getLine(void)
{
	const size_t sizeIncrement = 10;
	char *buffer = malloc(sizeIncrement);
	char *currentPosition = buffer;
	size_t maximumLength = sizeIncrement;
	size_t length = 0;
	int character;

	if(currentPosition == NULL) { return NULL; }

	while(1){
		character = fgetc(stdin);
		if(character == '\n') break;

		if(++length >= maximumLength){
			char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);

			if(newBuffer == NULL){
				free(buffer);
				return NULL;
			}
			

			currentPosition = newBuffer + (currentPosition - buffer);
			buffer = newBuffer;
		}
		*currentPosition++ = character;
	}
	*currentPosition = '\0';
	return buffer;
}

int main()
{
	int matrix[2][3] = {{1,2,3,}, {4,5,6,}};

	for(int i = 0; i < 2; i++)
	{
		printf("&matrix[%d]: %p sizeof(matrix[%d]): %d\n", i , &matrix[i], i,sizeof(matrix[i]));
	}


	for(int i = 0; i < 2; i++)
	{
		printf("&matrix[%d]: %p sizeof(matrix[%d]): %d\n", i , matrix[i], i,sizeof(matrix[i]));
	}

	int vector[5] = {1,2,3,4,5};
	int *pv = vector;

	printf("%p\n",vector);
	printf("%p\n",&vector[0]);
	printf("%p\n",&vector);


	printf("%p\n",&matrix);
	printf("%p\n",&matrix[0]);
	printf("%p\n",matrix);

	int value =3 ;
	for(int i =0; i<5; i++){
		*pv++ *= value;
		printf("%d\n", vector[i]);
	}
	
	char *buffer = getLine();
	printf("[%s]\n", buffer);

	char *bb = (char *)malloc(strlen("  cat")+1);
	strcpy(buffer, "  cat");
	printf("%s\n", trim(buffer));
	return 0; 
}
