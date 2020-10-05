// Assignment 4 for CS 1337.013
// Programmer: Muhammad Khizar
// Description: Phone Book Application: functions for book class .
// <This has all the funtions to add and remove entries, as well as
// constructor and destructor for PhoneBook class.>


#include "-mxk170009-PhoneBook.h"

// no argument constructor

PhoneBook::PhoneBook()
{
    maximumSize = 10;
    entries = new PhoneEntry[maximumSize];
    Uentry = 0;
}

// one argument constructor

PhoneBook::PhoneBook(unsigned int s)
{
    maximumSize = s;
    entries = new PhoneEntry[s];
    Uentry = 0;
}

// copy constructor

PhoneBook::PhoneBook(const PhoneBook &otherBook)
{
    *this = otherBook;
}

// = operator function

const PhoneBook& PhoneBook::operator=(const PhoneBook &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    maximumSize = rhs.maximumSize;
    delete[] entries;
    entries = new PhoneEntry[maximumSize];
    Uentry = rhs.Uentry;

    for(unsigned int i = 0; i < Uentry; i++)
    {
        entries[i] = rhs.entries[i];
    }
    return *this;
}

// decstructor

PhoneBook::~PhoneBook()
{
    delete[] entries;
    maximumSize = 0;
    Uentry = 0;
}

// [] operator function

const PhoneEntry& PhoneBook::operator[](unsigned int position)const
{
    return entries[position];
}

// function to check position of entry

const PhoneEntry& PhoneBook::phoneEntryAt(unsigned int position)const
{
    if(position >= 0 && position < Uentry)
    {
        return entries[position];
    }
}

// add function to add entry
void PhoneBook::add(std::string name,std::string number)
{
    if(Uentry >= maximumSize)
    {
        std::cout << "Entry Full" << std::endl;
        return;
    }
    else
    {
        entries[Uentry++] = PhoneEntry(name,number);
    }

}

//remove function

void PhoneBook::remove(const PhoneEntry &entry)
{
    for(unsigned int i = 0; i < Uentry; i++)
    {
        if(entry == entries[i])
        {
            for(unsigned int j = i; j < Uentry - 1; j++)
            {
                entries[j] = entries[j+1];
            }
            Uentry--;
            return;
        }
    }
}

// remove by name function
void PhoneBook::removeByName(std::string name)
{
    for(unsigned int i = 0; i < Uentry; i++)
    {
        if(name == entries[i].getName())
        {
            remove(entries[i]);
        }
    }
}

// function to remove by number

void PhoneBook::removeByNumber(std::string number)
{
    for(unsigned int i = 0; i < Uentry; i++)
    {
        if(number == entries[i].getNumber())
        {
            remove(entries[i]);
        }
    }
}

unsigned int PhoneBook::getSize() const
{
    return Uentry;
}
