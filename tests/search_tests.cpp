#include "search_tests.h"

#include "contact.h"
#include "contact_manager.h"
#include "test_data.h"
#include "helpers.h"

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

bool testLinearContactNotFound()
{
    ContactManager manager = populateManager(StandardContacts);

    std::vector<Contact*> found_contact = manager.searchContactsByName("Zed");

    bool exactly_zero = found_contact.size() == 0;
     
    return exactly_zero;
}

bool testLinearEmptyManager()
{
    ContactManager manager;
    std::vector<Contact*> found_contact = manager.searchContactsByName("Alice");

    bool exactly_zero = found_contact.size() == 0;
    bool manager_size = manager.contactSize() == 0;

    return exactly_zero && manager_size;
}

bool testLinearEmptyQueryReturnsAll()
{
    ContactManager manager = populateManager(StandardContacts);

    std::vector<Contact*> found_contact = manager.searchContactsByName("");

    bool exactly_manager_size = found_contact.size() == manager.contactSize();
     
    return exactly_manager_size;
}
