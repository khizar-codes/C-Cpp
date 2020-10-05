/*
 * userListCommands.cpp
 *
    This file has the class constructors and executors to get the
    menu options going once the program starts.
 */
#include "userListCommands.h"

#include <iostream>
#include <string>


insertCommand::insertCommand(userList &ids, std::istream &in, std::ostream &out)
	: userListCommand(ids, in, out)
{
}

insertCommand::~insertCommand()
{
}

void insertCommand::execute()
{
	std::string userName = read("Enter the User ID to be added:");
	std::string password = read("Enter the password for user " + userName + ":");

	bool result = userIds.add(userName, password);

	if (result)
	{
		display("User " + userName+ " was successfully added");
	}
	else
	{
		display("User " + userName+ " could not be added and may already exist");
	}
}

printCommand::printCommand(userList &ids, std::istream &in, std::ostream &out)
	: userListCommand(ids, in, out)
{

}

printCommand::~printCommand()
{
}

void printCommand::execute()
{
	display("Current list of users and passwords\n");

	userIds.print(out);
}

findCommand::~findCommand()
{

}

findCommand::findCommand(userList &ids, std::istream &in, std::ostream &out)
	: userListCommand(ids, in, out)
{

}

void findCommand::execute()
{
    std::string findName = read("Enter the user id to be found:");

    bool result = userIds.find(findName);

    if (result)
	{
		display("User " + findName+ " was found");
	}
	else
	{
		display("User " + findName+ " could not be found");
	}
}

updateCommand::~updateCommand()
{

}

updateCommand::updateCommand(userList &ids, std::istream &in, std::ostream &out)
	: userListCommand(ids, in, out)
{

}

void updateCommand::execute()
{
    std::string updateName = read("Enter the user id to be found:");

    bool result = userIds.find(updateName);

    if (result)
	{
	    std::string updatePassword = read("Enter the password for " + updateName + " to be updated: ");
		userIds.update(updateName, updatePassword);
		std::cout << "Updated successfully!\n";
	}
	else
	{
		display("\nUser could not be found, Not Updated.\n");
	}

}

eraseCommand::~eraseCommand()
{

}

eraseCommand::eraseCommand(userList &ids, std::istream &in, std::ostream &out)
	: userListCommand(ids, in, out)
{

}

void eraseCommand::execute()
{
    std::string eraseName = read("Enter the user id to be erased:");

    bool result = userIds.find(eraseName);

    if(result)
    {
        userIds.erase(eraseName);
        std::cout << eraseName << " has been successfully erased.\n";
    }
    else
    {
        std::cout << "Name could not be found, therefore not erased." << std::endl;
    }

}

printReverseCommand::printReverseCommand(userList &ids, std::istream &in, std::ostream &out)
	: userListCommand(ids, in, out)
{
}

printReverseCommand::~printReverseCommand()
{
}

void printReverseCommand::execute()
{
	display("Current list of users and passwords in REVERSE order\n");

	userIds.printReverse(out);
}
