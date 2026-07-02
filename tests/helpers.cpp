#include "helpers.h"

ContactManager populateManager(const std::vector<Contact> &argument_contacts)
{   ContactManager manager;

    for(const Contact& contact: argument_contacts)
    {
        manager.addContact(contact);
    }
    return manager;
}