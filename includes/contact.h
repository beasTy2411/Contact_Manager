#pragma once

#include<string>

class Contact
{
    private:
        std::string name;
        std::string number;
        std::string email;

    public:
        Contact(std::string name, std::string number = "", std::string email = "");
        void displayContact() const;
        const std::string& getName() const;
        const std::string& getNumber() const;
        const std::string& getEmail() const;
        void Contact::setName(const std::string& name);
};
