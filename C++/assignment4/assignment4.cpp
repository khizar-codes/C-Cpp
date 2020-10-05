/*
    // Assignment 4 for CS 1337.013
    // Programmer: <Muhammad Khizar>
    // Description:
    // <This program gets user input for user name and password. It has different
    // options to do different things with the list of the data the user inputs
    // such as find update print erase print in reverse, etc. The point is to
    // create and update a list of user name and passwords. There are many classes
    // classes for menu, command and template classes for stack.>
 */

#include "memoryLeak.h"

#include <iostream>
#include <string>

// #including all the files with the classes

#include "userList.h"
#include "menuList.h"
#include "userListCommands.h"
#include "stack.h"

using namespace std;

int main()
{
	// create the phone book
	userList users;

	// create the commands
	findCommand find(users, std::cin, std::cout);
	insertCommand insert(users, std::cin, std::cout);
	printCommand print(users, std::cin, std::cout);
	updateCommand update(users, std::cin, std::cout);
	eraseCommand erase(users, std::cin, std::cout);
	printReverseCommand printReverse(users, std::cin, std::cout);


	// build the menuList and menuItems
	menuList menu("UserID management:");
	menuItem findItem('f',"find", find);
	menuItem insertItem('i', "insert", insert);
	menuItem printItem('p',"print", print);
	menuItem updateItem('u', "update", update);
	menuItem eraseItem('e', "erase", erase);
    menuItem printReverseItem('r', "reverse", printReverse);

	// add the menuItem values to the menulist
	menu.add(findItem);
	menu.add(insertItem);
	menu.add(printItem);
	menu.add(updateItem);
	menu.add(eraseItem);
	menu.add(printReverseItem);

	// couting the title
	std::cout << "Starting the UserID management application\n" << endl;

	// run the menu
	menu.start();

	// program ends.
	return 0;
}
