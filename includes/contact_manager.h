#pragma once

#include "contact.h"

#include <vector>

class ContactManager
{
    private:
        std::vector<Contact> contacts;

    public:
        ContactManager();
        bool addContact(const Contact& contact);
        Contact* searchContact(const std::string& query);
        bool deleteContact(const std::string& number);
        bool editContact(const int& choice, const std::string& data, Contact* contact);
        bool displayAllContacts() const;
        bool sortAllContacts();
        bool saveToFile();
        bool loadFromFile();
};

