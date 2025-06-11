#include"cezar.h"


int main(int argc, char **argv) {

    if (argc != 5) {
        printf("Неправильные аргументы командной строки\n");
        return 1;
    }
    
    char* input_file_name = malloc(strlen(argv[1]) + 1); //+1 для терминального нуля (\0), который обозначает конец строки в C
    char* cezar_file_name = malloc(strlen(argv[2]) + 1);
    char* decezar_file_name = malloc(strlen(argv[3]) + 1);

    if (!input_file_name || !cezar_file_name || !decezar_file_name) {
        printf("Ошибка выделения памяти\n");
        free(input_file_name);
        free(cezar_file_name);
        free(decezar_file_name);
        return 1;
    }

    strcpy(input_file_name, argv[1]);
    strcpy(cezar_file_name, argv[2]);
    strcpy(decezar_file_name, argv[3]);
    int shift = atoi(argv[4]);
    
    Cezar(input_file_name, cezar_file_name, shift);
    DeCezar(cezar_file_name, decezar_file_name, shift);
    compare_files(argv[1], argv[3]);
    //printf("%d",compare_files("input.txt", "out.txt"));

    free(input_file_name);
    free(cezar_file_name);
    free(decezar_file_name);

}

//gcc cezar.c -c
//gcc cezar_f.c -c
//gcc cezar.h -c
//gcc --shared cezar.o cezar_f.o -o libMYLIB.so
//gcc cezar.c -o cezar -L. -lMYLIB -Wl,-rpath=.
//./cezar /home/valeria/c-prog2/rgr/input.txt /home/valeria/c-prog2/rgr/output.txt /home/valeria/c-prog2/rgr/third.txt 3


