cmake_minimum_required(VERSION 3.10)

project(Contact_Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Contact_Manager_Prod
    src/main.cpp
    src/contact.cpp
    src/contact_manager.cpp
    src/main_utility.cpp
)

target_include_directories(Contact_Manager_Prod PRIVATE includes)

add_executable(Contact_Manager_Test
    src/contact.cpp
    src/contact_manager.cpp
    src/main_utility.cpp
    tests/test_main.cpp
    tests/test_runner.cpp
    tests/contact_tests.cpp
    tests/helpers.cpp
    tests/search_tests.cpp
    tests/test_data.cpp
    tests/delete_tests.cpp      
)

target_include_directories(Contact_Manager_Test PRIVATE includes)