
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Lab10.h"

// DRIVER FUNCTION
int main()
{
	char* filename = (char*)malloc(sizeof(char) * 20);

	printf("\n Enter filename: ");
	if (filename == 0 || !scanf("%s", filename))
	{
		printf("\n Incorrect filename input");
		return -1;
	}

	vector_t str;
	init_vector(&str);
	print_id(&str, filename); // calling the parse function

	print_vector(&str);
	destroy(&str);
	return (0);
}