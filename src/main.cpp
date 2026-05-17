#include "includes/contact.h"
#include "includes/contact_manager.h"

#include <iostream>

int main()
{   
    ContactManager manager;

    int running = 1;
    int choice = -1;
    do
    {   
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "0. Quit";
        std::cout << "Enter choice: " << std::endl;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
        {
            
            std::string name;
            std::string number;
            std::string email;

            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            std::cout << "\nEnter Number: ";
            std::getline(std::cin, number);
            std::cout << "\nEnter Email: ";
            std::getline(std::cin, email);
            Contact newContact(name, number, email);
            manager.addContact(newContact);
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