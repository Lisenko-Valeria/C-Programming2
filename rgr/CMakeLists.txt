cmake_minimum_required(VERSION 3.10)
project(cezar_project LANGUAGES C)


add_library(cezar_lib SHARED cezar_f.c cezar.c)
target_include_directories(cezar_lib PUBLIC include)

# Основная программа
add_executable(cezar cezar.c)
target_link_libraries(cezar cezar_lib)


find_package(cmocka REQUIRED)

enable_testing()

add_executable(cezar_tests main_test.c)
target_include_directories(cezar_tests PRIVATE include)
target_link_libraries(cezar_tests cezar_lib cmocka)
    
add_test(NAME cezar_tests COMMAND cezar_tests)

#cmake .. and make
#./cezar /home/valeria/c-prog2/rgr/input.txt /home/valeria/c-prog2/rgr/output.txt /home/valeria/c-prog2/rgr/third.txt 3
#./cezar_tests