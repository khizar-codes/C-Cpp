// Assignment 4 for CS 1337.013
// Programmer: Muhammad Khizar
// Description: Phone Book Application: 1st class function.
// <Has a class that has an array of Phone Entry classes. Also
// has functions to modify and add to the array.>



#ifndef MXK170009PHONEBOOK_H_INCLUDED
#define MXK170009PHONEBOOK_H_INCLUDED
#include<iostream>
#include<string>
#include "mxk170009PhoneEntry.h"

class PhoneBook
{
private:
    // array of phone entry
    // max size of array

    unsigned int maximumSize;
    PhoneEntry *entries;


public:

    // variable to check how many entries are being used
    unsigned int Uentry;


    // constructors and destructors

    PhoneBook();
    PhoneBook(unsigned int maxEntries);
    PhoneBook(const PhoneBook &otherBook);
    ~PhoneBook();

    // functions to modify array and add or remove info

    void add(std::string name, std::string number);
    void removeByName(std::string name);
    void removeByNumber(std::string number);
    void remove(const PhoneEntry &entry);
    unsigned int getSize() const;
    const PhoneEntry& phoneEntryAt(unsigned int position) const;
    const PhoneEntry& operator[](unsigned int position) const;
    const PhoneBook& operator=(const PhoneBook &rhs);
};

#endif // MXK170009PHONEBOOK_H_INCLUDED
