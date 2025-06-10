cmake_minimum_required(VERSION 3.10)
project(SortingAlgorithms LANGUAGES C)

set(CMAKE_C_STANDARD 11)

# Основная программа
add_executable(SortingAlgorithms src/func.c src/main.c)

# Тесты
find_package(CMocka REQUIRED)
#add_executable(SortingTests test/main_test.c src/func.c)
#target_link_libraries(SortingTests PRIVATE cmocka m)

add_executable(test1 test/test1.c src/func.c)
target_link_libraries(test1 PRIVATE cmocka m)

add_executable(test2 test/test2.c src/func.c)
target_link_libraries(test2 PRIVATE cmocka m)

add_executable(test3 test/test3.c src/func.c)
target_link_libraries(test3 PRIVATE cmocka m)

add_executable(test4 test/test4.c src/func.c)
target_link_libraries(test4 PRIVATE cmocka m)

add_executable(test5 test/test5.c src/func.c)
target_link_libraries(test5 PRIVATE cmocka m)

add_executable(test6 test/test6.c src/func.c)
target_link_libraries(test6 PRIVATE cmocka m)

enable_testing()
#add_test(NAME SortingTests COMMAND SortingTests)
add_test(NAME test_FillRand COMMAND test1)
add_test(NAME test_SelectSort COMMAND test2)
add_test(NAME test_ShakerSort COMMAND test3)
add_test(NAME test_InsertSort COMMAND test4)
add_test(NAME test_BubbleSort COMMAND test5)
add_test(NAME test_Bubble_Shaker_Select_Insert COMMAND test6)