#pragma once

// NUMBER SEARCH

bool testSearchByNumberFound();
bool testSearchByNumberNotFound();

// LINEAR SEARCH

bool testLinearSingleContactFound();
bool testLinearMultiplePrefixMatches();
bool testLinearCaseInsensitive();
bool testLinearContactNotFound();
bool testLinearEmptyManager();
bool testLinearEmptyQueryReturnsAll();

// BINARY SEARCH

bool testBinarySingleMatchingContact();
bool testBinaryMultiplePrefixMatch();
bool testBinaryCaseInsensitiveSearch();
bool testBinaryNoPrefixMatch();
bool testBinaryFirstContactPrefix();
bool testBinaryLastContactPrefix();
bool testBinaryEmptyPrefixSearch();
bool testBinaryEmptyManager();
