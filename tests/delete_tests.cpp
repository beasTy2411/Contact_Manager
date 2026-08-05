#include "delete_tests.h"

#include "contact.h"
#include "contact_manager.h"
#include "test_data.h"
#include "helpers.h"

bool testDeleteExistingContact()
{
    ContactManager manager = populateManager(StandardContacts);
    int pre_contacts_size = manager.contactSize();
    std::vector<Contact*>found = manager.searchContactsByName("Alice");
    if(found.empty())
        return false;

    manager.deleteContact(found[0]);
    int post_contacts_size = manager.contactSize();

    bool size_reduced = pre_contacts_size - post_contacts_size == 1;
    found = manager.searchContactsByName("Alice");
    bool not_found = found.empty();

    return size_reduced && not_found;
}

bool testDeleteOneFromSamePrefixContact()
{
    ContactManager manager = populateManager(PrefixContacts);
    int pre_delete_size = manager.contactSize();
    std::vector<Contact*>found = manager.searchContactsByName("Al");
    if(found.empty())
        return false;

    Contact* selected_contact = nullptr;
    for(Contact* contact: found)
    {
        if(contact->getName() == "Alice")
            {
                selected_contact  = contact;
                break;
            }
    }
    if(selected_contact == nullptr)
        return false;   

    bool is_deleted = manager.deleteContact(selected_contact);
    int post_delete_size = manager.contactSize();

    bool size_reduced = pre_delete_size - post_delete_size == 1;
    found = manager.searchContactsByName("Alice");
    bool not_found = found.empty();

    return is_deleted && size_reduced && not_found;
}

bool testDeleteOnlyContact()
{
    ContactManager manager;
    Contact Alice("Alice", "123456789", "alice@gmail.com");
    manager.addContact(Alice);

    std::vector<Contact*> found = manager.searchContactsByName("Alice");
    if(found.empty())
        return false;

    bool is_deleted = manager.deleteContact(found[0]);
    int contacts_size = manager.contactSize();

    found = manager.searchContactsByName("Alice");
    bool not_found = found.empty();

    return is_deleted && not_found && contacts_size == 0;
}

bool  testDeleteNullContact()
{
    ContactManager manager = populateManager(StandardContacts);
    bool is_deleted = manager.deleteContact(nullptr);

    return !is_deleted;
}