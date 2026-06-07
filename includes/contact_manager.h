#pragma once

#include "contact.h"

#include <vector>

// CONTACT MANAGER CLASS
/* STORES ALL THE CONTACTS IN A VECTOR */
/* MANAGES ALL THE BACKEND OPERATIONS */
class ContactManager
{
    private:
        // VECTOR OF CONTACT OBJECT TYPE
        std::vector<Contact> contacts;

    public:
        // CONSTRUCTOR
        ContactManager();

        /* ADD CONTACT TO THE VECTOR
            RETURNS BOOL VALUE BASED ON OPERATION STATUS*/
        bool addContact(const Contact& contact);

        /* SEARCH CONTACT FROM THE VECTOR
            RETURNS A POINTER TO THE SEARCHED CONTACT*/ 
        Contact* searchContact(const std::string& query);

        /* DELETE CONTACT FROM THE VECTOR
            RETURN BOOL VALUE BASED ON OPERATION STATUS*/
        bool deleteContact(const std::string& number);

        /* DELETE FUNCTION OVERLOAD USING ARGUMENT POINTER TO A CONTACT
            RETURNS BOOL VALUE BASED ON OPERATION STATUS*/
        bool deleteContact(Contact* contact);

        /* EDIT THE INFORMATION OF AN EXISTING CONTACT IN THE VECTOR
            RETURN BOOL VALUE BASED ON OPERATION STATUS*/
        bool editContact(const int& choice, const std::string& data, Contact* contact);

        /* DISPLAY ALL THE CONTACTS PRESENT IN THE VECTOR TO THE SCREEN
            RETURN BOOL VALUE BASED ON OPERATION STATUS */
        bool displayAllContacts() const;

        /* SORTS THE CONTACTS IN THE VECTOR ALPHABETICALLY
            RETURN BOOL VALUE BASED ON OPERATION STATUS
            ALSO AUTORUNS ON "ADD CONTACT" OPERATION*/
        bool sortAllContacts();

        /* SAVES THE CONTACTs PRESENT IN RUNTIME MEMORY TO A FILE
            RETURN BOOL VALUE BASED ON OPERATION STATUS
            ALSO AUTORUNS ON ALL CRUD OPERATIONS*/
        bool saveToFile();

        /* LOAD THE CONTACTS FROM THE FILE TO THE RUNTIME MEMORY
            RETURNS BOOL VALUE BASED ON OPERATION STATUS
            ALSO RUNS ON THE EXECUTION OF THE APPLICATION*/
        bool loadFromFile();

        /* SEARCH CONTACTS BY NAME 
            RETURN A VECTOR OF FOUND CONTACT WHICH CONTAINS THE QUERIED SUBSTRING */
        std::vector<Contact*> searchContactsByName(const std::string &query);

        /* HELPER FUNCTION FOR SEARCH CONTACTS BY NAME
            IT CONVERTS THE INPUT TO LOWERCASE AND RETURNS THE STRING*/
        void toLowerCase(std::string& query);
};

