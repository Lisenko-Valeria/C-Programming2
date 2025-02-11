#include <stdlib.h>

int main() {
    // модель процессора
    //-m 1 — только первое совпадение
    // awk - редактор для обработки данных, поступающих на вход
    // -F — указать разделитель полей
    // system() позволяет выполнить строку, как если бы она была введена в командной строке
    system("grep -m 1 'model name' /proc/cpuinfo | awk -F ': ' '{print $2}'");

    // частота процессора
    system("grep -m 1 'cpu MHz' /proc/cpuinfo | awk -F ': ' '{print $2}'");
}

//(cat cpu/cpuinfo)
