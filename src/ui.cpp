#include "ui.h"

#include <iostream>
#include <limits>

Contact* selectContactByName(ContactManager& manager)
{
                std::string name;
                std::cout << "Please enter the name: ";
                std::getline(std::cin, name);
                std::cout<< std::endl;

                std::vector<Contact*> found_contacts 
                    = manager.searchContactsByName(name);
                
                if(found_contacts.empty())
                {
                    std::cout << "No contacts found" << std::endl;
                    return nullptr;
                }
                
                int i = 1;
                for(const Contact* contact: found_contacts)
                {   
                    std::cout << i << ": ";
                    contact->displayContact();
                    i++;
                }

                int choice;
                std::cout << "Please choose a contact: ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if(choice < 1 || choice > found_contacts.size())
                {
                    std::cout << "Please enter a valid choice" << std::endl;
                    return nullptr;
                }

                return found_contacts[choice - 1];
}