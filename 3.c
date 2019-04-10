#include <stdio.h>

int main()
{
	char *titles[] = {"A tale of Two Cities",\
		"Wuthering Heights", "Don Quixote",\
			"Odyssey", "Moby-Dick", "Hamlet",\
			"Gulliver`s Travels"};
	char **bestBooks[3];
	char **englishBooks[4];
	char *testBooks[3]; 
	
	const int limit =500;
	int *const cpi = &limit;
	*cpi = 400;
	printf("%d\n", limit);	
	testBooks[0] = titles[1];
	printf("%s\n", testBooks[0]);
	printf("%p\n", testBooks[0]);
	printf("%p\n", &testBooks[0]);

	bestBooks[0] = &titles[0];
	bestBooks[1] = &titles[3];
	bestBooks[2] = &titles[5];
	
	englishBooks[0] = &titles[0];
	englishBooks[1] = &titles[1];
	englishBooks[2] = &titles[5];
	englishBooks[3] = &titles[6];
	printf("%s\n", *englishBooks[1]);
	printf("%s\n", titles[1]);
	printf("%p\n", titles[1]);
	printf("%p\n", &titles[1]);
	printf("%p\n", englishBooks[1]);
	printf("%c\n", **englishBooks[1]);

	return 0;
}
