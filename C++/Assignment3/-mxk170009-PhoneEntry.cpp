// Assignment 4 for CS 1337.013
// Programmer: Muhammad Khizar
// Description: Phone Book Application: functions for 2nd class.
// <Has all functions for the PhoneEntry class.>


#include "-mxk170009-PhoneEntry.h"

// constructor

    PhoneEntry::PhoneEntry()
    {
        setName("");
        setNumber("");
    }

// copy constructor

    PhoneEntry::PhoneEntry(const PhoneEntry &other)
    {
        *this = other;
    }

// 2 argument constructor

    PhoneEntry::PhoneEntry(std::string newName, std::string newNumber)
    {
        setName(newName);
        setNumber(newNumber);
    }

// destructor

    PhoneEntry::~PhoneEntry()
    {
        // nothing
    }

// = operator constructor to assign values

const PhoneEntry& PhoneEntry::operator=(const PhoneEntry &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    else
    {
        name = rhs.getName();
        number = rhs.getNumber();
    }
}

// == to compare values

bool PhoneEntry::operator==(const PhoneEntry &rhs) const
{
    if (this == &rhs)
    {
        return true;
    }
    if (name == rhs.getName() && number == rhs.getNumber())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// != constructor to check for values

bool PhoneEntry::operator!=(const PhoneEntry &rhs) const
{
    if (this == &rhs)
    {
        return false;
    }
    if (name == rhs.getName() && number == rhs.getNumber())
    {
        return false;
    }
    else
    {
        return true;
    }
}

// << operator to cout the data

std::ostream& operator<<(std::ostream &out, const PhoneEntry &rhs)
{
    out << rhs.getName() << " " << rhs.getNumber() << std::endl;
    return out;
}
