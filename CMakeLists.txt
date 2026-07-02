cmake_minimum_required(VERSION 3.10)

project(Contact_Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Contact_Manager_Prod
    src/main.cpp
    src/contact.cpp
    src/contact_manager.cpp
    src/main_utility.cpp
    tests/test_data.cpp
    tests/helpers.h
)

target_include_directories(Contact_Manager_Prod PRIVATE includes)
