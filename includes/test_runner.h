#pragma once

#include <string>

void runTest(const std::string& test_name, bool(*func)(), int& total_passed, int& total_failed, int& total_tests);