#ifndef __PHONE__BOOK__H
#define __PHONE__BOOK__H
#include "PhoneEntry.cpp"

class PhoneBook
{
private:
    unsigned int maximumSize;
    PhoneEntry *entries;

public:
    PhoneBook();
    PhoneBook(unsigned int maxEntries);
    PhoneBook(const PhoneBook &otherBook);
    ~PhoneBook();

    void add(string name, string number);
    void removeByName(string name);
    void removeByNumber(string number);
    void remove(const PhoneEntry &entry);
    unsigned int getSize() const;
    const PhoneEntry& phoneEntryAt(unsigned int position) const;
    const PhoneEntry& operator[](unsigned int position) const;
    const PhoneBook& operator=(const PhoneBook &rhs);


};

#endif
