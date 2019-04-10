#include <stdio.h>

int (*fptr1)(int);

typedef int (*funcptr)(int);

int square(int num){
	return num*num;
}

int add(int num1, int num2){
	return num1 + num2;
}

int sub(int num1, int num2){
	return num1 - num2;
}


typedef int (*fptrOperation)(int, int);


fptrOperation select(char opcode){
	switch(opcode){
		case '+': return add;
		case '-': return sub;
	}
	return NULL;
}

int compute(fptrOperation operation, int num1, int num2){
	return operation(num1, num2);
}

int evaluate(char opcode, int num1, int num2){
	fptrOperation operation = select(opcode);
	return operation(num1, num2);
}

int (*operations[128])(int, int) = {NULL};

void initializeOperationsArray(){
	operations['+'] = add;
	operations['-'] = sub;
}

int evaluateArray(char opcode, int num1, int num2){
	fptrOperation operation;
	operation = operations[opcode];
	return operation(num1, num2);
}

int main()
{
	int n = 5;
	fptr1= square;
	printf("%d squared is %d\n", n, fptr1(n));

	funcptr fptr2;
	fptr2 = square;
	printf("%d squared is %d\n", n, fptr2(n));

	printf("%d\n",compute(add,5,6));
	printf("%d\n",compute(sub,5,6));

	printf("%d\n", evaluate('+', 5, 6));
	printf("%d\n", evaluate('-', 5, 6));

	initializeOperationsArray();
	printf("%d\n", evaluateArray('+', 5, 6));
	printf("%d\n", evaluateArray('-', 5, 6));

	fptrOperation fptr3 = add;
	if(fptr3 == add){
		printf("fptr1 points to add function\n");
	}else{
		printf("fptr1 does not point to add function\n");
	}

	return 0;
}
