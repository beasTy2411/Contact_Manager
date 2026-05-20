#include "contact.h"
#include "contact_manager.h"

#include <iostream>

int main()
{   
    ContactManager manager;

    int running = 1;
    int choice = -1;
    do
    {   
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Search Contact" << std::endl;
        std::cout << "3. Delete Contact" << std::endl;
        std::cout << "4. Display All Contacts" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();
        std::cout << std::endl;

        switch (choice)
        {
        case 1:
        { 
            std::string name;
            std::string number;
            std::string email;

            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Number: ";
            std::getline(std::cin, number);
            std::cout << "Enter Email: ";
            std::getline(std::cin, email);
            std::cout << std::endl;
            Contact newContact(name, number, email);
            manager.addContact(newContact);
            break;
        }
        
        case 2:
        {
            std::string query;
            std::cout << "Please enter the Number: " ;
            std::getline(std::cin, query);
            std::cout << std::endl;

            Contact *contact = manager.searchContact(query);
            if(contact != nullptr)
            {
                std::cout << "Contact Found: \n";
                contact->displayContact();
                std::cout << std::endl;
            }
            else{
                std::cout << "Contact not found.\n" << std::endl;
            }
            break;
        }
        
        case 3:
        {
            std::string number;
            std::cout << "Please enter the number: ";
            std::getline(std::cin, number);
            std::cout << std::endl;

            bool found = false;
            found = manager.deleteContact(number);

            if(found) {std::cout << "Contact deleted successfully\n" << std::endl;}
            else {std::cout << "Contact not found\n" << std::endl;}
            break;
        }

        case 4:
        {   
            manager.displayAllContacts();
            break;
        }
        case 0:
            running = 0;
            break;
        default:
            break;
        }

    }while(running);
}