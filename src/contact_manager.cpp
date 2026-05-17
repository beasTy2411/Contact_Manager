#include "contact_manager.h"

#include <iostream>
#include <algorithm>

#define DEBUG 1

void ContactManager::addContact(const Contact& contact)
{
    contacts.push_back(contact);
    // std::sort(contacts.begin(), contacts.end());

#if DEBUG
    displayAllContacts();
#endif
}

void ContactManager::deleteContact(std::string name)
{
    
}

Contact* ContactManager::searchContact(std::string query)
{

}

void ContactManager::displayAllContacts() const
{
    for(const Contact& contact : contacts)
    {
        contact.displayContact();
    }
}

void ContactManager::saveToFile()
{
    
}

void ContactManager::loadFromFile()
{

}