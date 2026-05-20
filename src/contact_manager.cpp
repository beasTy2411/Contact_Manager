#include "contact_manager.h"

#include <iostream>
#include <algorithm>

#define DEBUG 0

void ContactManager::addContact(const Contact& contact)
{   
    size_t duplicate = 0;
    if(searchContact(contact.getNumber()))
    {
        duplicate = 1;
    }
    if(!duplicate)
    {
        contacts.push_back(contact);
        std::cout << "Contact Added Successfully \n" << std::endl;
    }
    else
    {
        std::cout << "Duplicate Contact \n" << std::endl;
    }
    // std::sort(contacts.begin(), contacts.end());

#if DEBUG
    displayAllContacts();
#endif
}

bool ContactManager::deleteContact(const std::string& number)
{   
    std::vector<Contact>::iterator it;
    for(it = contacts.begin(); it != contacts.end(); ++it)
    {
        if(it->getNumber() == number)
            break;
    }

    if(it == contacts.end()) return false;

    contacts.erase(it);
    return true;    
}

Contact* ContactManager::searchContact(const std::string& query)
{
    for(Contact& contact : contacts)
    {
        if(contact.getNumber() == query)
        {
            return &contact;
        }
    }
    return nullptr;
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