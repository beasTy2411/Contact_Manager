#include "contact.h"

#include<iostream>

Contact::Contact(std::string name, std::string number, std::string email) 
        : name(name), number(number), email(email)
{
}


void Contact::displayContact() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Email: " << email << std::endl << std::endl;
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

void Contact::setNumber(const std::string& number)
{
    this->number = number;
}

void Contact::setEmail(const std::string& email)
{
    this->email = email;
}