#include "test_runner.h"
#include "contact_tests.h"
#include "search_tests.h"

#include <iostream>

int main()
{   
    int total_passed = 0;
    int total_failed = 0;
    int total_tests  = 0;

    std::cout << "\n\nRunning Tests..........\n" << std::endl;
    std::cout << "Running Contact Tests" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    runTest("Add Contact", testAddContact, total_passed, total_failed, total_tests);
    runTest("Duplicate Phone Number", testDuplicatePhoneNumber, total_passed, total_failed, total_tests);
    std::cout << "-------------------------------------------\n" << std::endl;

    std::cout << "Running Linear Search Tests" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    runTest("Single Contact Found",testLinearSingleContactFound, total_passed, total_failed, total_tests);
    runTest("Multiple Prefix Matches",testLinearMultiplePrefixMatches, total_passed, total_failed, total_tests);
    runTest("Case Insensitive Search",testLinearCaseInsensitive, total_passed, total_failed, total_tests);
    runTest("Contact Not Found",testLinearContactNotFound, total_passed, total_failed, total_tests);
    runTest("Searching Empty Manager",testLinearEmptyManager, total_passed, total_failed, total_tests);
    runTest("Searching Empty Query",testLinearEmptyQueryReturnsAll, total_passed, total_failed, total_tests);
    std::cout << "-------------------------------------------\n" << std::endl;

    std::cout << "Running Binary Search Tests" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    runTest("Single Contact Found",testBinarySingleMatchingContact, total_passed, total_failed, total_tests);
    runTest("Multiple Prefix Matches",testBinaryMultiplePrefixMatch, total_passed, total_failed, total_tests);
    runTest("Case Insensitive Search",testBinaryCaseInsensitiveSearch, total_passed, total_failed, total_tests);
    runTest("Contact Not Found",testBinaryNoPrefixMatch, total_passed, total_failed, total_tests);
    runTest("First Contact Search",testBinaryFirstContactPrefix, total_passed, total_failed, total_tests);
    runTest("Last Contact Search",testBinaryLastContactPrefix, total_passed, total_failed, total_tests);
    runTest("Searching Empty Manager",testBinaryEmptyManager, total_passed, total_failed, total_tests);
    runTest("Searching Empty Query",testBinaryEmptyPrefixSearch, total_passed, total_failed, total_tests);
    std::cout << "-------------------------------------------\n" << std::endl;

    std::cout << "Tests Completed" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Total Tests Passed: " << total_passed << std::endl;
    std::cout << "Total Tests Failed: " << total_failed << std::endl;
    std::cout << "Total Tests Done: " << total_tests << std::endl;
    std::cout << "-------------------------------------------\n" << std::endl;

    return 0;
}