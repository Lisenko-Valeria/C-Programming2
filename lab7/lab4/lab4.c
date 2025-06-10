#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

void replace(char *line) {
    int length=strlen(line);
    int start=0;
    
    for (int i=0; i<=length; i++) {
        if (!(isalpha(line[i]))) {
            // переворачиваем буквы в слове от start до i-1
            int left = start;
            int right = i - 1;
            while (left < right) {
                char temp = line[left];
                line[left] = line[right];
                line[right] = temp;
                left++;
                right--;
            }
            
            start = i + 1;
        }
    }
}
    
int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "%s: неправильное количество аргументов \n", argv[0]);
        return(0);
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Ошибка при открытии файла");
        return(0);
    }
    FILE *temp_file = fopen("/home/valeria/c-prog2/lab4/ff.txt", "w");
    if (temp_file == NULL) {
        perror("Ошибка при открытии файла");
        fclose(input_file);
        return(0);
    }
        
    char line[1024];
    while (fgets(line, sizeof(line), input_file)) {
        replace(line);
        fprintf(temp_file, "%s", line);
        //printf("%s", line);
    }
    
    fclose(input_file);
    fclose(temp_file);
}


