#include "includes/contact.h"

#include<iostream>

Contact::Contact(std::string name, std::string number, std::string email) 
        : name(name), number(number), email(email)
{
}


void Contact::displayContact() const
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Number: " << number << "\n";
    std::cout << "Email: " << email << "\n";
}

const std::string& Contact::getName() const
{
    return name;
}
const std::string& Contact::getNumber() const
{
    return number;
}
const std::string& Contact::getEmail() const
{
    return email;   
}

void Contact::setName(const std::string& name)
{
    this->name = name;
}