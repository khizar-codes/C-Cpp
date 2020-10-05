// Assignment 4 for CS 1337.013
// Programmer: Muhammad Khizar
// Description: Phone Book Application: 2nd class
// <Used to hold data for entries. An array of this is made
// in phonebook class whenever it is called>

#ifndef __PHONE_ENTRY_H
#define __PHONE_ENTRY_H
#include<iostream>
#include<string>

class PhoneEntry
{
    // variables to hold entry data

    std::string name;
    std::string number;

public:

    // constructor destructor

    PhoneEntry();
    PhoneEntry(const PhoneEntry &other);
    PhoneEntry(std::string newName, std::string newNumber);
    ~PhoneEntry();

    // accessor and mutator functions for private variables

    std::string getName() const
    {
        return name;
    }
    std::string getNumber() const
    {
        return number;
    }
    void setName(std::string newName)
    {
        name = newName;
    }
    void setNumber(std::string newNumber)
    {
        if(newNumber.length() <= 10)
        {
            number = newNumber;
        }
    }

    // operator functions to check

    const PhoneEntry& operator=(const PhoneEntry &rhs);
    bool operator==(const PhoneEntry &rhs) const;
    bool operator!=(const PhoneEntry &rhs) const;


};

// << operator to cout data

std::ostream& operator<<(std::ostream &out, const PhoneEntry &rhs);


#endif
