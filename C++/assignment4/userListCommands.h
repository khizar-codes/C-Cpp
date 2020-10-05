/*
 * userListCommands.h
 *  //command classes to get menu working and to give user options
    on what to do
 */

#ifndef USERLISTCOMMANDS_H_
#define USERLISTCOMMANDS_H_

#include "memoryLeak.h"

#include <string>

#include "command.h"
#include "userList.h"

class userListCommand: public command
{
	protected:
		userList &userIds;
		std::istream &in;
		std::ostream &out;

		userListCommand(userList &ids, std::istream &in, std::ostream &out)
	     : userIds(ids), in(in), out(out)
		{
		}

		void display(const std::string &message)
		{
			out << message << "\n";
		}

		std::string read(const std::string &prompt)
		{
			std::string result;
			out << prompt << "\n";
			getline(in, result);
			return result;
		}
};

// lets user add entry
class insertCommand : public userListCommand
{
	public:
		insertCommand(userList &ids, std::istream &in, std::ostream &out);
		~insertCommand();
		void execute() override;
};

// prints whole list of user addition
class printCommand : public userListCommand
{
	public:
		printCommand(userList &ids, std::istream &in, std::ostream &out);
		~printCommand();
		void execute() override;
};

// finds entry of username and password using username
class findCommand : public userListCommand
{
    public:
        findCommand(userList &ids, std::istream &in, std::ostream &out);
        ~findCommand();
        void execute() override;
};

// updates password for username after asking user for the username
class updateCommand : public userListCommand
{
public:
    updateCommand(userList &ids, std::istream &in, std::ostream &out);
    ~updateCommand();
    void execute() override;
};

//erases item from the list asking for the username
class eraseCommand : public userListCommand
{
    public:
        eraseCommand(userList &ids, std::istream &in, std::ostream &out);
        ~eraseCommand();
        void execute() override;
};

// prints the list in reverse
class printReverseCommand : public userListCommand
{
    public:
        printReverseCommand(userList &ids, std::istream &in, std::ostream &out);
        ~printReverseCommand();
        void execute() override;
};

#endif /* USERLISTCOMMANDS_H_ */
