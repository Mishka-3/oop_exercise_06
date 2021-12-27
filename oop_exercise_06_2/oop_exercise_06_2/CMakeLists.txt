# CMakeList.txt: проект CMake для oop_exercise_06_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (oop_exercise_06_2 "oop_exercise_06_2.cpp" "oop_exercise_06_2.h" "containers/list.h" "containers/queue.h" "my_allocator" "Point" "Trapezoid" )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
