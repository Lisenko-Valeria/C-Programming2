#include "cezar.h"

wchar_t cezar_char(wchar_t c, int shift) {
    //wchar_t - char для хранения "широких" символов
    wchar_t *lower_rus = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    wchar_t *upper_rus = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    wchar_t *pos; 
    int index;
    
    if ((pos = wcschr(lower_rus, c)) != NULL) {
        index = (pos - lower_rus + shift) % 33;
        if (index < 0) index += 33;
        return lower_rus[index];
    }
    else if ((pos = wcschr(upper_rus, c)) != NULL) {
        index = (pos - upper_rus + shift) % 33;
        if (index < 0) index += 33;
        return upper_rus[index];
    }
    return c;
}

void print_file(const char* filename) {
    FILE *file = fopen(filename, "r, ccs=UTF-8");
    if (!file) {
        wprintf(L"Ошибка открытия файла %s для чтения\n", filename);
        return;
    }
    wint_t wc;
    while ((wc = fgetwc(file)) != WEOF) { 
        putwchar(wc);
    }
    wprintf(L"\n\n");

    fclose(file);
}

int Cezar(char* input_filename, char* cezar_filename, int shift){
    setlocale(LC_ALL, ""); // Установка локали из окружения
    FILE *input_file, *cezar_file;
    wint_t wc; 
    wprintf(L"До шифровки:\n");
    print_file(input_filename);

    input_file = fopen(input_filename, "r, ccs=UTF-8");
    if (!input_file) {
        perror("Ошибка открытия входного файла");
        return 1;
    }

    cezar_file = fopen(cezar_filename, "w, ccs=UTF-8");

    if (!cezar_file) {
        perror("Ошибка создания выходных файлов");
        fclose(input_file);
        return 1;
    }

    while ((wc = fgetwc(input_file)) != WEOF) { 
        wchar_t cezared_char = cezar_char(wc, shift);
        fputwc(cezared_char, cezar_file);
    }

    fclose(input_file);
    fclose(cezar_file);

    wprintf(L"После шифровки:\n");
    print_file(cezar_filename);
}

int DeCezar(char* cezar_filename, char* decezar_filename, int shift){
    setlocale(LC_ALL, ""); // Установка локали из окружения
    FILE *cezar_file, *decezar_file;
    wint_t cezared_char; 
    wprintf(L"До дешифровки:\n");
    print_file(cezar_filename);

    cezar_file = fopen(cezar_filename, "r, ccs=UTF-8");
    decezar_file = fopen(decezar_filename, "w, ccs=UTF-8");

    if (!cezar_file || !decezar_file) {
        perror("Ошибка создания выходного файлов");
        return 1;
    }

    while ((cezared_char = fgetwc(cezar_file)) != WEOF) { 
        wchar_t decezared_char = cezar_char(cezared_char, -shift);
        fputwc(decezared_char, decezar_file);
    }

    fclose(cezar_file);
    fclose(decezar_file);

    wprintf(L"После дешифровки:\n");
    print_file(decezar_filename);
}

int compare_files(char *input_filename, char *decezar_filename) {
    FILE *input_file = fopen(input_filename, "r, ccs=UTF-8");
    FILE *decezar_file = fopen(decezar_filename, "r, ccs=UTF-8");
    
    if (!input_file || !decezar_file) {
        if (input_file) fclose(input_file);
        if (decezar_file) fclose(decezar_file);
        return -1; 
    }
    
    wint_t c1, c2;
    int result = 0; // 0 - файлы идентичны, 1 - различаются
    
    while (1) {
        c1 = fgetwc(input_file);
        c2 = fgetwc(decezar_file);
        
        // Проверка на конец файла или ошибку чтения
        if (c1 == WEOF || c2 == WEOF) {
            if (c1 != c2) result = 1; // один файл закончился раньше
            break;
        }
        
        if (c1 != c2) {
            result = 1;
            break;
        }
    }
    
    fclose(input_file);
    fclose(decezar_file);
    if (result == 0) wprintf(L"same");
    else wprintf(L"not the same");
    wprintf(L"\n");
    return result;
}