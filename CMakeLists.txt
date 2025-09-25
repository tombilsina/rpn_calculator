cmake_minimum_required(VERSION 3.20)
project(RPN_Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включаем директории с исходными файлами
include_directories(include)

# Создаем БИБЛИОТЕКУ с нашей логикой
add_library(rpn_lib src/rpn.cpp)
target_include_directories(rpn_lib PUBLIC include)

# Добавляем исполняемый файл
add_executable(rpn_calculator
    src/main.cpp
    src/rpn.cpp
)
target_link_libraries(rpn_calculator PRIVATE rpn_lib)

# Устанавливаем свойства для более строгой компиляции
set_target_properties(rpn_calculator PROPERTIES
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
enable_testing()
add_subdirectory(tests)
