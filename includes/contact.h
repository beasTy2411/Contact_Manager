#pragma once

#include<string>

// CONTACT CLASS
class Contact
{
    // CONTACT INFORMATION
    private:
        std::string name;
        std::string number;
        std::string email;

    public:
        // CONSTRUCTOR
        Contact(std::string name, std::string number = "", std::string email = "");
        
        // GETTER FUNCTIONS
        const std::string& getName() const;
        const std::string& getNumber() const;
        const std::string& getEmail() const;

        // INHERENT DISPLAY FUNCTIONS
        void displayContact() const;

        // SETTER FUNCTIONS
        void setName(const std::string& name);
        void setNumber(const std::string& number);
        void setEmail(const std::string& email);
};
