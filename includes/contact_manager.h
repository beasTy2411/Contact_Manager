#pragma once

#include "contact.h"

#include <vector>

class ContactManager
{
    private:
        std::vector<Contact> contacts;

    public:
        void addContact(const Contact& contact);
        bool deleteContact(const std::string& number);
        Contact* searchContact(const std::string& query);
        void displayAllContacts() const;
        void saveToFile();
        void loadFromFile();
};

