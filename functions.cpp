
#define _CRT_SECURE_NO_WARNINGS

#include "Lab10.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_ch(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int ignore(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
        ch == '\n'|| ch == '!' || ch == '\''||
        ch == '\\'|| ch == '|')
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
    if (str[0] >= '0' && str[0] <= '9' || str[0] == '"')
        return 0;
    for (int i = 0; str[i+1] != '\0'; i++)
    {
        if (ignore(str[i]))
            return 0;
    }
    return 1;
}

void print_id(char* filename)
{
    FILE* fp;
    if (!(fp = fopen(filename, "r")))
        return;

    char* word;
    printf("\n Identifiers, parsed from \"%s\": ", filename);
    while ((word = readWord(fp)) != NULL)
    {
        if(validIdentifier(word) && !isKeyword(word))
            printf("\n\t%s", word);
        free(word);
    }
}

char* readWord(FILE* fp) {
    char ch = ' ';

    while (ignore(ch))
    {
        ch = fgetc(fp);
        if (ch == EOF || !ch)
            return NULL;
    }

    int size = 1;
    while (!ignore(ch))
    {
        if (ch == '"')
        {
            while (1)
            {
                size++;
                if ((ch = fgetc(fp)) == EOF || !ch || ch == '"')
                    break;
            }
        }
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

