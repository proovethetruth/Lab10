
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

	print_id(filename); // calling the parse function
	return (0);
}

// DRIVER FUNCTION
//int main()
//{
//	// maximum legth of string is 100 here
//	// char str[100] = "int main { int a = 0; }";
//	char* filename = (char*)malloc(sizeof(char) * 20);
//	if (!filename)
//	{
//		printf("\n Allocation error");
//		return -2;
//	}
//
//	printf("\n Input filename: ");
//	if (scanf("%s", filename) != 1)
//	{
//		printf(" Input error\n");
//		return -2;
//	}
//
//
//	parse(filename); // calling the parse function
//	free(filename);
//	return (0);
//}
//
//FILE* fp;
//fp = fopen(filename, "r");
//if (!fp)
//{
//	printf("\n File not found");
//	return;
//}
//
//char* str = (char*)malloc(sizeof(char) * 10000);
//if (!str)
//{
//	printf("\n File not found");
//	return;
//}
//
//for (int i = 0; !feof(fp); i++) {
//	if ((fscanf(fp, "%c", &str[i])) != 1)
//		break;
//}
