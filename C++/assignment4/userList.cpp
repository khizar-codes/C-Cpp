/*
 * userList.cpp
 *
    this file contains user list functions to update and modify
 */

#include <iostream>
#include <iomanip>

#include "userList.h"
#include "stack.h"

bool userList::find(std::string userid) const
{
	// return true if the user id exists and false otherwise
	return ids.find(userid) != ids.end();
}
bool userList::add(const userEntry &entry)
{
	bool result = false;
	if ( !find(entry.getName()) )
	{
		// item was not found
		// add it
		auto insertResult = ids.insert(std::make_pair(entry.getName(), entry.getPassword()));
		result = insertResult.second;
	}
	return result;
}

bool userList::erase(std::string userid)
{
	auto numErased = ids.erase(userid);

	return numErased != 0;
}

bool userList::update(const userEntry &entry)
{
	bool result = false;
	if ( find(entry.getName()) )
	{
		// item was found
		// update it
		ids[entry.getName()] = entry.getPassword();
		result = true;
	}

	return result;
}

void userList::print(std::ostream &out) const
{
    // setw to make a table
	const int NAME_LEN = 20;
	const int PASSWORD_LEN = 25;

	// couting title
	out << std::setw(NAME_LEN) << "User id";
	out << std::setw(PASSWORD_LEN) << "Password" << std::endl;

	// printing the user list first to last
	for (const auto &elem : ids)
	{
		out << std::setw(NAME_LEN) << elem.first;
		out << std::setw(PASSWORD_LEN) << elem.second << std::endl;
	}
}

void userList::printReverse(std::ostream &out) const
{
    // creating 2 stacks. one for username and for password
    Stack<string> *s = new Stack<string>();
    Stack<string> *r = new Stack<string>();

    // setw to format output
    const int NAME_LEN = 20;
	const int PASSWORD_LEN = 25;

	// couting title
	out << std::setw(NAME_LEN) << "User id";
	out << std::setw(PASSWORD_LEN) << "Password" << std::endl;

	int i = 0;
    // loop for stacks to take in input

	for (const auto &elem : ids)
	{
	    s->push(elem.first);
		r->push(elem.second);
		i++;
	}

	//loop to print stack

    for (int x = 0; x < i; x++)
    {
        string user = s->pop();
		string pass = r->pop();
		cout << std::setw(NAME_LEN) << user;
		cout << std::setw(PASSWORD_LEN) << pass << std::endl;
    }

    // deleting stacks
    delete s;
    delete r;
}
