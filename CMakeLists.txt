cmake_minimum_required(VERSION 3.10)

project(Contact_Manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(Contact_Manager
    src/main.cpp
    src/contact.cpp
    src/contact_manager.cpp
)

target_include_directories(Contact_Manager PRIVATE includes)