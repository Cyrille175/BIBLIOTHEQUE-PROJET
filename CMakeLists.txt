cmake_minimum_required(VERSION 3.16)
project(BibliothequeProjet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(BibliothequeProjet
    src/main.cpp
    src/Date.cpp
    src/Book.cpp
    src/Member.cpp
    src/Loan.cpp
    src/NotificationService.cpp
    src/Library.cpp
)