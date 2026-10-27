cmake_minimum_required(VERSION 4.0)
project(vyro_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  add_compile_options(/W3 /WX /permissive- /EHsc)
else()
  add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

add_executable(vyro_demo
  src/vyro_demo.cpp
)
target_include_directories(vyro_demo PRIVATE src)

enable_testing()
add_test(NAME version_check COMMAND vyro_demo --version-check)