// CLASS CONTACT MANAGER IMPLEMENTATION
#include "contact_manager.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

#define DEBUG 0

ContactManager::ContactManager()
{
    loadFromFile();
}

bool ContactManager::addContact(const Contact& contact)
{   
    if(searchContact(contact.getNumber()))
    {
       return false;
    } 

    contacts.push_back(contact);
    saveToFile();
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
    saveToFile();
    return true;    
}


bool ContactManager::editContact(const int& choice, const std::string& data, Contact* contact)
{
    switch(choice)
    {
        case 1:
        {
            contact->setName(data);
            if(!saveToFile()) return false;
            return true;
        }
        case 2:
        {   
            Contact *sContact = searchContact(data);
            if(sContact != nullptr && sContact != contact) 
            {   
                return false;
            }
            else    
            {
                contact->setNumber(data);
                if(!saveToFile()) return false;
                return true;
            }
        }
        case 3:
        {
            contact->setEmail(data);
            if(!saveToFile()) return false;
            return true;
        }
        default:
        return false;
            break;
    }
}

bool ContactManager::displayAllContacts() const
{   
    if(contacts.size() == 0)
    {
        return false;
    }
    else
    {
        for(const Contact& contact : contacts)
        {
            contact.displayContact();
        }
    }
    return true;
}

bool ContactManager::sortAllContacts()
{
    std::sort(contacts.begin(), contacts.end(),
             [](const Contact& a, const Contact& b)
             {return a.getName() < b.getName();}
            );
    if(!saveToFile())
    {
        return false;
    }

    return true;
}

bool ContactManager::saveToFile()
{
    std::ofstream myfile;
    myfile.open("data/contacts.csv", std::ios::trunc);

    if(!myfile.is_open())
    {
       return false;
    }

    for(auto it = contacts.begin(); it != contacts.end(); ++it )
    {
        myfile << it->getName() << "," << it->getNumber() << "," << it->getEmail();
        myfile << std::endl;
    }

    myfile.close();
    return true;    
}

bool ContactManager::loadFromFile()
{
    std::ifstream myfile;
    myfile.open("data/contacts.csv");

    if(!myfile.is_open())
    {
        return false;
    }

    contacts.clear();

    std::vector<std::string> row;
    std::string line, word;
    while(std::getline(myfile, line, '\n'))
    {   
        row.clear();
        std::stringstream s(line);
        while(std::getline(s, word, ','))
        {
            row.push_back(word);
        }
        
        if(row.size() == 3)
        {
            Contact contact(row[0], row[1], row[2]); 
            contacts.push_back(contact);
        }   

        #if DEBUG
        std::cout << "Name: " << row[0] << std::endl;
        std::cout << "Number: " << row[1] << std::endl;
        std::cout << "Email: " << row[2] << std::endl;
        #endif
        
    }

    myfile.close();
    return true;
}