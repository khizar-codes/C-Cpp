// Assignment 4 for CS 1337.013
// Programmer: Muhammad Khizar
// Description: Phone Book Application: Main File.
// <This is powered using the PhoneBook.cpp.h and
// PhoneEntry.cpp.h. There are 2 classes It takes in information about a person
// ... The name and phone number. It is passed into a function which adds
// it to an array of PhoneEntry. You can add an entry by using name and phone
// number. You can remove an entry using the name, number or by both. >


#include "-mxk170009-PhoneBook.h"
#include "-mxk170009-PhoneEntry.h"

int main()
{

    // phone book object

    PhoneBook newBook(10);

    // adding entries

    newBook.add("john", "9724249309");
    newBook.add("don", "9724242782");
    newBook.add("ron", "2145242627");
    newBook.add("phone", "2142243291");

    std::cout << "\n";

    // displaying

    for(unsigned int i = 0; i <= newBook.getSize(); i++)
    {
        std::cout << newBook[i] << std::endl;
    }

    std::cout << "\n\n";

    // removing entry by both name and number

    newBook.remove(PhoneEntry("john","9724249309"));

    for( unsigned int i = 0; i < newBook.getSize(); i++)
    {
        std::cout << newBook.phoneEntryAt(i)<< std::endl;
    }

    std::cout << "\n\n";

    // removing entry by name

    newBook.removeByName("ron");

    // removing entry by number

    newBook.removeByNumber("2142243291");

    // displaying

    for(unsigned int i = 0; i < newBook.getSize(); i++)
    {
        std::cout << newBook.phoneEntryAt(i)<< std::endl;
    }

}
