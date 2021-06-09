
#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>

int is_ch(char ch);
int ignore(char ch);
int isKeyword(char* str);
int validIdentifier(char* str);

void print_id(char* filename);
char* readWord(FILE* fp);

#endif // !LAB10_H