#include "main_utility.h"

#include <iostream>
#include <ios>
#include <limits>
#include <chrono>

int main()
{   
    ContactManager manager;

    int running = 1;    //variable for the render loop
    int choice = -1;    //variable to store menu choice
    
    /* MAIN MENU
        HANDLES ALL THE PRESENTATION LAYER OPERATION 
        SUCH AS TAKING INPUT FROM USER
        SEPERATION FROM THE BACKEND API*/
    do
    {   
        std::cout << std::endl;
        std::cout << "---------- CONTACT MANAGER ----------" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Search Contact" << std::endl;
        std::cout << "3. Search Contact by Name" << std::endl;
        std::cout << "4. Delete Contact" << std::endl;
        std::cout << "5. Delete Contact Using Name" << std::endl;
        std::cout << "6. Edit Contact" << std::endl;
        std::cout << "7. Display All Contacts" << std::endl;
        // std::cout << "6. Save Contacts to File" << std::endl;
        std::cout << "8. Sort All Contacts" << std::endl;
        std::cout << "9. Load Contacts from File" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();
        std::cout << std::endl;

        switch (choice)
        {
            //ADD CONTACT 
            case 1:
            { 
                std::string name;
                std::string number;
                std::string email;
                bool status;

                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Number: ";
                std::getline(std::cin, number);
                std::cout << "Enter Email: ";
                std::getline(std::cin, email);
                std::cout << std::endl;
                Contact newContact(name, number, email);
                status = manager.addContact(newContact);

                if(status == true)
                    std::cout << "Contact Added Successfully \n" << std::endl;
                else
                    std::cout << "Duplicate Contact \n" << std::endl;

                manager.sortAllContacts();
                break;
            }
            
            // DISPLAY CONTACT
            case 2:
            {
                std::string query;
                std::cout << "Please enter the Number: " ;
                std::getline(std::cin, query);
                std::cout << std::endl;

                Contact *contact = manager.searchContactbyNumber(query);
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
            
            //SEARCH CONTACT BY NAME
            case 3:
            {  
                std::string input;
                std::cout << "Please enter the query: ";
                std::getline(std::cin, input);
                std::cout<<std::endl;
                
                std::vector<Contact*> found_contacts 
                            = manager.binarySearchContactsByName(input);
                            
                if(!found_contacts.empty())
                {
                    std::cout << "--- Found Contacts ---" << std::endl;
                    for(const Contact* contact: found_contacts)
                    {
                        std::cout << contact->getName() << std::endl;
                        std::cout << contact->getNumber() << std::endl;
                        std::cout << contact->getEmail() << std::endl;
                        std::cout << std::endl;
                    }
                }
                else
                {
                    std::cout << "No Contacts Found" << std::endl;
                }

                std::cout << std::endl;
                break;
            }

            // DELETE CONTACT
            case 4:
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
            
            // DELETE CONTACT USING NAME
            case 5:
            {
                Contact* contact = selectContactByName(manager);
                bool success = manager.deleteContact(contact);

                if(success)
                {
                    std::cout << "Deleted the contact successfully" << std::endl;
                }
                else
                {
                    std::cout << "Failed to delete the selected contact" << std::endl;
                }
                break;
            }

            // EDIT CONTACT
            case 6:
            {
                Contact *contact = selectContactByName(manager);
                
                if(contact == nullptr)
                {
                    std::cout << "Failed to edit the contact" << std::endl;
                    break;
                }

                contact->displayContact();

                std::cout << "What do you want to edit?" << std::endl;
                std::cout << "1. Name" << std::endl;
                std::cout << "2. Number" << std::endl;
                std::cout << "3. Email" << std::endl;
                std::cout << "Please enter your choice: ";
                std::cin >> choice;
                std::cout << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                bool status;
                if(choice == 1)
                {   
                    std::string name;
                    std::cout << "Please enter the new Name: ";
                    std::getline(std::cin, name);
                    status = manager.editContact(choice, name, contact);
                    if(status)
                    {
                        std::cout << "Name updated successfully" << std::endl;
                    }
                }
                else if(choice == 2)
                {   
                    std::string number;
                    std::cout << "Please enter the new Number: ";
                    std::getline(std::cin, number);
                    status = manager.editContact(choice, number, contact);
                    if(status)
                    {
                        std::cout << "Number updated successfully" << std::endl;
                    }
                    else
                    {
                        std::cout << "Number already present" << std::endl;
                    }
                }
                else if(choice == 3)
                {   
                    std::string email;
                    std::cout << "Please enter the new Email: ";
                    std::getline(std::cin, email);
                    status = manager.editContact(choice, email, contact);
                    if(status)
                    {
                        std::cout << "Email updated successfully" << std::endl;
                    }
                }
                else{
                    std::cout << "Please enter correct choice" << std::endl;
                }
                manager.sortAllContacts();
                break;
            }

            // DISPLAY ALL CONTACTS
            case 7:
            {   
                bool status = manager.displayAllContacts();
                if(!status) 
                    std::cout << "Contact List is Empty\n" << std::endl;
                break;
            }

            /* SAVING DATA TO THE FILE IMPLEMENTED AUTOMATICALLY */ 
            // case 6: 
            // {   bool status;
            //     status = manager.saveToFile();
            //     if(status)
            //     {
            //         std::cout << "File saved successfully\n" << std:: endl;
            //     }
            //     else{
            //         std::cout << "Failed to open the file\n" << std::endl;
            //     }
            //     break;
            // }

            // SORTING THE CONTACTS
            case 8: 
            {
                bool status;
                status = manager.sortAllContacts();

                if(status)
                {
                    std::cout << "Contacts Sorted Successfully\n" << std::endl;
                }
                else
                {
                    std::cout << "Failed to Sort Contacts\n" << std::endl;
                }
                break;
            }

            // LOADING CONTACTS FROM FILE TO RUNTIME MEMORY
            case 9: 
            {   bool status;
                status = manager.loadFromFile();

                if(status)
                {
                    std::cout << "Loaded Contacts from File\n" << std::endl;
                }
                else
                {
                    std::cout << "Failed to open the file";
                }
                break;
            }

            // EXIT THE APPLICATION
            case 0:
                running = 0;
                break;
            default:
                break;
            }

    }while(running);
}