
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_vector(vector_t* v) {
    v->arr = (char**)calloc(2, sizeof(char) * 2);
    v->size = 0;
    v->capacity = 2;
}

void destroy(vector_t* v) {
    for (int i = 0; i < (int)v->size; i++)
    {
        if (v->arr[i] != NULL)
            free(v->arr[i]);
    }
    v->size = 0;
}

void push_back(vector_t* str, char* word) {
    char** tmp = NULL;
    if (str->size == str->capacity)
    {
        str->capacity *= 2;
        tmp = (char**)calloc(str->capacity, str->capacity * sizeof(char));
        if (!tmp)
        {
            printf("\n\a ERROR: Can't allocate enough memory");
            return;
        }
        for (int i = 0; i < (int)str->size; i++)
        {
            tmp[i] = str->arr[i];
        }
        str->arr = tmp;
    }
    for (int i = 0; i < (int)str->size; i++)
    {
        if (strcmp(str->arr[i], word) == 0)
            return;
    }
    str->arr[str->size] = word;
    str->size++;
}

void print_vector(vector_t* str)
{
    if (str->size == 0)
        return;
    for (int i = 0; i < (int)str->size; i++)
        printf("\n %d. %s", i + 1, str->arr[i]);
}

int is_ch(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int is_num(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return 1;
    return 0;
}

int isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else")
        || !strcmp(str, "while") || !strcmp(str, "do")
        || !strcmp(str, "break") || !strcmp(str, "for")
        || !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto")
        || !strcmp(str, "NULL") || !strcmp(str, "EOF")
        || !strcmp(str, "FILE"))
        return 1;
    return 0;
}

int validIdentifier(char* str)
{
    if (is_num(str[0]))
        return 0;

    if (isKeyword(str))
        return 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if(!is_ch(str[i]) && !is_num(str[i]) && str[i] != '_')
            return 0;
    }
}

void print_id(vector_t* str, char* filename)
{
    FILE* fp;
    if (!(fp = fopen(filename, "r")))
        return;

    char* word;
    printf("\n Identifiers, parsed from \"%s\": ", filename);
    while ((word = readWord(fp)) != NULL)
    {
        if (validIdentifier(word))
            push_back(str, word);
    }
}

char* readWord(FILE* fp) {
    char ch = ' ';

    while (isDelimiter(ch))
    {
        ch = fgetc(fp);
        if (ch == EOF || !ch)
            return NULL;
    }

    int size = 1;
    while (!isDelimiter(ch))
    {
        if ((ch = fgetc(fp)) == EOF || !ch)
            break;
        size++;
    }
    fseek(fp, -(size * (int)sizeof(char)), 1);

    if (ch != EOF || !ch)
        size--;

    char* word = (char*)calloc(size, sizeof(char) * size + 1);
    if (!word)
    {
        printf("\n Allocation error.");
        return NULL;
    }
    for (int i = 0; i < size; i++)
        word[i] = fgetc(fp);
    word[size] = '\0';

    return word;
}


