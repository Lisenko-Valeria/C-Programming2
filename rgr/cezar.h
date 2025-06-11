#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //Корректное отображение русских символов 
#include <wchar.h> //Обработка многобайтовых символов (Unicode, UTF-8/16/32)
#include <wctype.h> //добавляет логику для анализа широких символов.

wchar_t cezar_char(wchar_t c, int shift);
void print_file(const char* filename);
int Cezar(char* input_filename, char* cezar_filename, int shift);
int DeCezar(char* cezar_filename, char* decezar_filename, int shift);
int compare_files(char *input_filename, char *decezar_filename);

