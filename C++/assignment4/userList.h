/*
 * userList.h
 *
    This file takes in user input and adds it to a list
    and has functions to modify it
 */

#ifndef USERLIST_H_
#define USERLIST_H_

#include "memoryLeak.h"
#include <iostream>
#include <string>
#include <map>
#include "stack.h"
class userEntry
{
	private:
	    // user input
		std::string userName;
		std::string userPassword;
	public:
	    // functions to make sure entry is right
		userEntry() : userEntry("","") {}
		userEntry(std::string name, std::string password)
			: userName(name), userPassword(password) { }
		virtual ~userEntry() {}
		bool verify(std::string password);
		std::string getName() const { return userName;}
		std::string getPassword() const { return userPassword;}
		void setName(std::string newName) { userName = newName;}
		void setPassword(std::string newPassword) {userPassword = newPassword;}
};

class userList
{
	private:
		std::map<std::string, std::string> ids;
		typedef std::map<std::string, std::string>::iterator iterator;
		typedef const iterator								 const_iterator;
	public:
	    // functions to make and add changes to the user list
		userList() : ids() {};
		virtual ~userList() {}
		bool find(std::string userid) const;
		bool add(std::string userid, std::string password)
		{
			return add(userEntry(userid, password));
		}
		bool add(const userEntry &entry);
		bool erase(std::string userid);
		bool update(std::string userid, std::string password)
		{
			return update(userEntry(userid, password));
		}
		bool update(const userEntry &entry);
		iterator begin() noexcept {return ids.begin();}
//		const_iterator begin() const noexcept {return ids.begin();}
		iterator end() noexcept {return ids.end();}
//		const_iterator end() const noexcept {return ids.end();}
		void print(std::ostream &out) const;
		void print() const { print(std::cout);}

		// prints user list in reverse order
		void printReverse(std::ostream &out) const;
        void printReverse() const
        {
            printReverse(std::cout);
        }
};

#endif /* USERLIST_H_ */
