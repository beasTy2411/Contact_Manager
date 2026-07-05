#include "test_runner.h"

#include <iostream>

void runTest(const std::string& test_name, bool(*test_function)(), int& total_passed, int& total_failed, int& total_tests)
{
    bool result = test_function();

    if(result)
        {
           std::cout << "[PASS]\t" << test_name << std::endl;
           total_passed++;
        }
    else
        {
            std::cout << "[FAIL]\t" << test_name << std::endl;
            total_failed++;
        }
    total_tests++;
}   