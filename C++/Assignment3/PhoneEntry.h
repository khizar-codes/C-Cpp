#ifndef __PHONE_ENTRY_H
#define __PHONE_ENTRY_H
#include<iostream>
#include<string>

class PhoneEntry
{
    std::string name;
    std::string number;

public:


    PhoneEntry();
    PhoneEntry(const PhoneEntry &other);
    PhoneEntry(std::string newName, std::string newNumber);
    ~PhoneEntry();

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
        if(newNumber.length() >= 10)
        {
            number = newNumber;
        }
    }

    const PhoneEntry& operator=(const PhoneEntry &rhs);
    bool operator==(const PhoneEntry &rhs) const;
    bool operator!=(const PhoneEntry &rhs) const;


};

std::ostream& operator<<(std::ostream &out, const PhoneEntry &rhs);


#endif
