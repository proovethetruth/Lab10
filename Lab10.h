
#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>

typedef struct {
    char** arr;
    size_t size;
    size_t capacity;
} vector_t;

void init_vector(vector_t* v);
void destroy(vector_t* v);
void push_back(vector_t* str, char* word);
void print_vector(vector_t* str);

int is_ch(char ch);
int ignore(char ch);
int isKeyword(char* str);
int validIdentifier(char* str);

void print_id(vector_t* str, char* filename);
char* readWord(FILE* fp);

#endif // !LAB10_H