//gcc main_test.c -c
//gcc cezar_f.o main_test.o -lcmocka -o tests
//./tests


#include "cezar.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>


static void test_cezar_char(void** state) {
    (void)state;
    assert_int_equal(cezar_char(L'а', 3), L'г');
    assert_int_equal(cezar_char(L'я', 1), L'а');
    assert_int_equal(cezar_char(L'Г', 3), L'Ё');
    assert_int_equal(cezar_char(L'А', -1), L'Я');
    assert_int_equal(cezar_char(L' ', 10), L' ');
    assert_int_equal(cezar_char(L'.', 3), L'.');
}

static void test_Cezar(void** state) {
    (void)state;
    
    char* input_file = "test_input.txt";
    char* encrypted_file = "test_encrypted.txt";
    wchar_t* text = L"Привет, мир!";
    int shift = 3;
    
    // Создаем тестовый файл
    FILE* file0= fopen(input_file, "w, ccs=UTF-8");
    fputws(text, file0);
    
    // Шифруем файл
    int result = Cezar(input_file, encrypted_file, shift);
    assert_int_equal(result, 0);
    
    // Проверяем, что файл создан
    FILE* file1 = fopen(encrypted_file, "r, ccs=UTF-8");
    assert_non_null(file1);
    if (file1) fclose(file1);
    
    // Удаляем временные файлы
    remove(input_file);
    remove(encrypted_file);
}

static void test_DeCezar(void** state) {
    (void)state;
    
    char* encrypted_file = "test_encrypted.txt";
    char* decrypted_file = "test_decrypted.txt";
    wchar_t* text = L"Привет, мир!";
    int shift = 5;
    
    // Создаем тестовые файлы
    FILE* file0= fopen(encrypted_file, "w, ccs=UTF-8");
    fputws(text, file0);
    int result = DeCezar(encrypted_file, decrypted_file, shift);
    assert_int_equal(result, 0);
    
    // Проверяем, что файл создан
    FILE* file1 = fopen(decrypted_file, "r, ccs=UTF-8");
    assert_non_null(file1);
    if (file1) fclose(file1);
    
    remove(encrypted_file);
    remove(decrypted_file);
}

static void test_compare_files(void** state) {
    (void)state;
    
    char* file_name_1 = "test_file1.txt";
    char* file_name_2 = "test_file2.txt";
    char* file_name_3 = "test_file3.txt";
    
    FILE* file1= fopen(file_name_1, "w, ccs=UTF-8");
    fputws(L"Один", file1);
    fclose(file1);
    FILE* file2= fopen(file_name_2, "w, ccs=UTF-8");
    fputws(L"Один", file2);
    fclose(file2);
    FILE* file3= fopen(file_name_3, "w, ccs=UTF-8");
    fputws(L"Два", file3);
    fclose(file3);

    int result = compare_files(file_name_1, file_name_2);
    assert_int_equal(result, 0);
    
    result = compare_files(file_name_1, file_name_3);
    assert_int_equal(result, 1);
    
    remove(file_name_1);
    remove(file_name_2);
    remove(file_name_3);
}

static void test_print_file(void** state) {
    (void)state;
    
    char* filename = "test_print.txt";
    wchar_t* text = L"Тестовый текст для печати";
    
    FILE* file0= fopen(filename, "w, ccs=UTF-8");
    fputws(text, file0);
    
    // Перенаправляем stdout в файл для проверки вывода
    freopen("test_output.txt", "w", stdout);
    print_file(filename);
    fclose(stdout);
    
    // Проверяем, что файл с выводом создан
    FILE* file = fopen("test_output.txt", "r");
    assert_non_null(file);
    if (file) fclose(file);
    
    remove(filename);
    remove("test_output.txt");
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_cezar_char),
        cmocka_unit_test(test_Cezar),
        cmocka_unit_test(test_DeCezar),
        cmocka_unit_test(test_compare_files),
        cmocka_unit_test(test_print_file),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}