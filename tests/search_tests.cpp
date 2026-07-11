#include "search_tests.h"

#include "contact.h"
#include "contact_manager.h"
#include "test_data.h"
#include "helpers.h"

#include <iostream>

/*ASSERTS THAT WE FOUND THE CONTACT BY THE QUERIED MOBILE NUMBER USING LINEAR SEARCH*/
bool testSearchByNumberFound()
{   
    Contact Alice("Alice", "123456789", "alice@gmail.com");
    ContactManager manager;

    manager.addContact(Alice);

    Contact* found_contact = manager.searchContactbyNumber("123456789");
    bool not_null = found_contact;

    bool is_alice = false;
    if(not_null)
    {
        is_alice = (found_contact->getName() == Alice.getName());
    }

    return not_null && is_alice;
}

/*ASSERTS THAT WE DID NOT FIND THE CONTACT BY THE QUERIED MOBILE NUMBER USING LINEAR SEARCH*/
bool testSearchByNumberNotFound()
{   
    Contact Alice("Alice", "123456789", "alice@gmail.com");
    ContactManager manager;

    manager.addContact(Alice);

    Contact* found_contact = manager.searchContactbyNumber("987654321");
    bool not_null = found_contact;

    if(!not_null) return true;
    else return false;
}

/*ASSERTS THAT WE FOUND THE CONTACT BY THE QUERIED NAME USING LINEAR SEARCH*/
bool testLinearSingleContactFound()
{   
    ContactManager manager = populateManager(StandardContacts);

    std::vector<Contact*> found_contact = manager.searchContactsByName("Charlie");

    bool not_empty = found_contact.size() == 1;
    
    bool is_charlie = false; 
    
    if(not_empty)
        is_charlie = found_contact[0]->getName() == "Charlie"  ;
     
    return not_empty && is_charlie;
}

/*ASSERTS THAT WE FOUND MULTIPLE CONTACTS CONTAINING THE QUERIED PREFIX USING LINEAR SEARCH*/
bool testLinearMultiplePrefixMatches()
{
    ContactManager manager = populateManager(PrefixContacts);
    std::vector<Contact*> found_contact = manager.searchContactsByName("Al");
    bool not_empty = found_contact.size() > 0 ? true : false;

    return not_empty;
}

/*ASSERTS THAT WE FOUND THE CONTACT CONTAINING THE QUERIED NAME BY CASE INSENSITIVE METHOD USING LINEAR SEARCH*/
bool testLinearCaseInsensitive()
{   
    ContactManager manager = populateManager(StandardContacts);
    
    std::vector<Contact*> found_contact = manager.searchContactsByName("CHARLIE");

    bool exactly_one = found_contact.size() == 1;
    
    bool is_charlie = false; 
    
    if(exactly_one)
        is_charlie = found_contact[0]->getName() == "Charlie"  ;
     
    return exactly_one && is_charlie;
}

/*ASSERTS THAT WE DID NOT FIND THE QUERIED CONTACT IN THE VECTOR USING LINEAR SEARCH*/
bool testLinearContactNotFound()
{
    ContactManager manager = populateManager(StandardContacts);

    std::vector<Contact*> found_contact = manager.searchContactsByName("Zed");

    bool exactly_zero = found_contact.size() == 0;
     
    return exactly_zero;
}

/*ASSERTS THAT THE CONTACT MANAGER IS EMPTY USING LINEAR SEARCH*/
bool testLinearEmptyManager()
{
    ContactManager manager;
    std::vector<Contact*> found_contact = manager.searchContactsByName("Alice");

    bool exactly_zero = found_contact.size() == 0;
    bool manager_size = manager.contactSize() == 0;

    return exactly_zero && manager_size;
}

/*ASSERTS THAT EMPTY QUERY RETURN ALL THE CONTACTS IN THE MANAGER USING LINEAR SEARCH*/
bool testLinearEmptyQueryReturnsAll()
{
    ContactManager manager = populateManager(StandardContacts);

    std::vector<Contact*> found_contact = manager.searchContactsByName("");

    bool exactly_manager_size = found_contact.size() == manager.contactSize();
     
    return exactly_manager_size;
}

/*ASSERTS THAT WE FOUND THE CONTACT BY THE QUERIED NAME USING BINARY SEARCH*/
bool testBinarySingleMatchingContact()
{   
    ContactManager manager = populateManager(StandardContacts);
    std::vector<Contact*> found_contact = manager.binarySearchContactsByName("Alice");

    bool exactly_one = found_contact.size() == 1;
    bool is_alice = false; 
    
    if(exactly_one)
        is_alice = found_contact[0]->getName() == "Alice"  ;

    return exactly_one && is_alice;
}

/*ASSERTS THAT WE FOUND MULTIPLE CONTACTS CONTAINING THE QUERIED PREFIX USING BINARY SEARCH*/
bool testBinaryMultiplePrefixMatch()
{   
    ContactManager manager = populateManager(PrefixContacts);
    std::vector<Contact*> found_contacts = manager.binarySearchContactsByName("Al");

    return found_contacts.size() == 3;
}

/*ASSERTS THAT WE FOUND THE CONTACT CONTAINING THE QUERIED NAME BY CASE INSENSITIVE METHOD USING BINARY SEARCH*/
bool testBinaryCaseInsensitiveSearch()
{   
    ContactManager manager = populateManager(StandardContacts);
    std::vector<Contact*> found_contacts = manager.binarySearchContactsByName("ALICE");

    bool exactly_one = found_contacts.size() == 1;
    bool is_alice = false; 
    
    if(exactly_one)
        is_alice = found_contacts[0]->getName() == "Alice"  ;

    return exactly_one && is_alice;
}

/*ASSERTS THAT WE DID NOT FIND THE QUERIED CONTACT IN THE MANAGER USING BINARY SEARCH*/
bool testBinaryNoPrefixMatch()
{
    ContactManager manager = populateManager(StandardContacts);
    std::vector<Contact*> found_contacts = manager.binarySearchContactsByName("Z");

    return found_contacts.size() == 0;
}

/*ASSERTS THAT THE FIRST CONTACT FOUND USING LINEAR SEARCH AND BINARY SEARCH IS SAME*/
bool testBinaryFirstContactPrefix()
{   
    ContactManager manager = populateManager(PrefixContacts);
    std::vector<Contact*> found_contacts = manager.binarySearchContactsByName("Al");

    std::vector<Contact*> double_check = manager.searchContactsByName("Al");
    bool same_contact = false;
    
    if(found_contacts.size() == double_check.size())
        same_contact = found_contacts[0]->getName() == double_check[0]->getName();

    return same_contact;
}

/*ASSERTS THAT THE LAST CONTACT FOUND USING LINEAR SEARCH AND BINARY SEARCH IS SAME*/
bool testBinaryLastContactPrefix()
{
    ContactManager manager = populateManager(PrefixContacts);
    std::vector<Contact*> found_contacts = manager.binarySearchContactsByName("Al");

    std::vector<Contact*> double_check = manager.searchContactsByName("Al");

    bool same_contact = false;
    
    if(found_contacts.size() == double_check.size())
        same_contact = found_contacts[found_contacts.size() - 1]->getName() == double_check[double_check.size() - 1]->getName();

    return same_contact;
}

/*ASSERTS THAT EMPTY QUERY RETURN ALL THE CONTACTS IN THE MANAGER USING BINARY SEARCH*/
bool testBinaryEmptyPrefixSearch()
{
    ContactManager manager = populateManager(PrefixContacts);
    std::vector<Contact*> found_contacts = manager.binarySearchContactsByName("");

    return found_contacts.size() == manager.contactSize();
}

/*ASSERTS THAT THE CONTACT MANAGER IS EMPTY USING BINARY SEARCH*/
bool testBinaryEmptyManager()
{
    ContactManager manager;
    std::vector<Contact*> found_contact = manager.binarySearchContactsByName("Alice");

    bool exactly_zero = found_contact.size() == 0;
    bool manager_size = manager.contactSize() == 0;

    return exactly_zero && manager_size;
}