#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
    entries = new PhoneEntry[10];
    maximumSize = 10;
    size = 0;
}
PhoneBook::PhoneBook(unsigned int s)
{
    entries = new PhoneEntry[s];
    maximumSize = s;
    size = 0;
}
PhoneBook::PhoneBook(const PhoneBook &otherBook)
{
    *this = otherBook;
}
const PhoneBook& PhoneBook::operator=(const PhoneBook &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    maximumSize = rhs.maximumSize;

    delete[] entries;

    entries = new PhoneEntry[maximumSize];

    size = rhs.size;

    for(int i = 0; i<size; i++)
    {
        entries[i] = rhs.entries[i];
    }

    return *this;
}
PhoneBook::~PhoneBook()
{
    delete[] entries;
    size = 0;
    maximumSize = 0;
}

const PhoneEntry& PhoneBook::operator[](unsigned int position)const
{
    if(position >= 0 && position < size)
    {
        return entries[position];
    }
}
const PhoneEntry& PhoneBook::phoneEntryAt(unsigned int position)const
{
    return (*this)[position];
}
void PhoneBook::add(std::string name,std::string number)
{
    if(size >= maximumSize)
    {
        std::cout << "Entry Full";
        return;
    }
    entries[size++] = PhoneEntry(name,number);
}
void PhoneBook::remove(const PhoneEntry &entry)
{
    for(int i = 0; i<size; i++)
    {
        if(entry == entries[i])
        {
            for(int j = i; j<size-1; j++)
            {
                entries[j] = entries[j+1];
            }
            size--;
            return;
        }
    }
}
void PhoneBook::removeByName(std::string name)
{
    for(int i = 0; i < size; i++)
    {
        if(name == entries[i].getName())
        {
            remove(entries[i]);
        }
    }
}
void PhoneBook::removeByNumber(std::string number)
{
    for(int i = 0; i < size; i++)
    {
        if(number == entries[i].getPhone())
        {
            remove(entries[i]);
        }
    }
}
