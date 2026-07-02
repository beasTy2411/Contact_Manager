#include "contact_tests.h"

#include "contact.h"
#include "contact_manager.h"

bool testAddContact()
{   
    Contact contact("Alice", "123456789", "alice@gmail.com");
    ContactManager manager;

    int initial_vector_size = manager.contactSize();

    bool contact_created = manager.addContact(contact);

    int final_vector_size = manager.contactSize();

    Contact* found_contact = manager.searchContactbyNumber(contact.getNumber());

    bool found_by_number;
    if(found_contact == nullptr) found_by_number = false;
    else if(contact.getNumber() == found_contact->getNumber()) found_by_number = true;
    else found_by_number = false;

    bool vector_size;
    if(final_vector_size - initial_vector_size == 1) vector_size = true;
    else vector_size = false;

    if(contact_created && found_by_number && vector_size) return true;
    else return false;
}

bool testDuplicatePhoneNumber()
{   
    Contact Alice("Alice", "123456789", "alice@gmail.com");
    Contact Bob("Bob", "123456789", "Bob@gmail.com");

    ContactManager manager;

    manager.addContact(Alice);

    int initial_vector_size = manager.contactSize();
    bool Bob_created = manager.addContact(Bob);

    int final_vector_size = manager.contactSize();
    
    bool vector_size;
    if(final_vector_size == initial_vector_size) vector_size = true;
    else vector_size = false;

    Contact* found_contact = manager.searchContactbyNumber(Bob.getNumber());
    bool found_by_number;
    if(found_contact == nullptr) found_by_number = false;
    else if(Bob.getName() == found_contact->getName()) found_by_number = true;
    else found_by_number = false;

    if(!Bob_created && !found_by_number && vector_size) return true;
    else return false;
}
