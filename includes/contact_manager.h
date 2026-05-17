#pragma once

#include "contact.h"

#include <vector>

class ContactManager
{
    private:
        std::vector<Contact> contacts;

    public:
        void addContact(const Contact& contact);
        void deleteContact(std::string name);
        Contact* searchContact(std::string query);
        void displayAllContacts() const;
        void saveToFile();
        void loadFromFile();
};

