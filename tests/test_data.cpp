#include "test_data.h"

const std::vector<Contact> StandardContacts = {
    Contact("Alice", "123456789", "alice@gmail.com"),
    Contact ("Bob", "234567891", "bob@gmail.com"),
    Contact ("Charlie", "345678912", "charlie@gmail.com"),
    Contact ("Dave", "456789123", "dave@gmail.com")
};

const std::vector<Contact> DuplicateNamesContacts = {
    Contact("Alice", "123456789", "alice@gmail.com"),
    Contact ("Alice", "234567891", "alice@gmail.com"),
    Contact ("Charlie", "345678912", "charlie@gmail.com"),
    Contact ("Dave", "456789123", "dave@gmail.com")
};

const std::vector<Contact> PrefixContacts = {
    Contact("Alice", "123456789", "alice@gmail.com"),
    Contact ("Albert", "234567891", "albert@gmail.com"),
    Contact("Alina", "567891234", "alina@gmail.com"),
    Contact ("Athena", "345678912", "athena@gmail.com"),
    Contact ("Dave", "456789123", "dave@gmail.com")
};