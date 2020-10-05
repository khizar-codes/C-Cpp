/*
 * stack.h
 *
 */

#ifndef STACK_H_
#define STACK_H_

#include <cstddef>
#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

//template class stacks
template <class Type>
class Stack;

// template node class, friend class of stack
template <class Type>
class node
{
	friend class Stack<Type>;
	private:
		Type 		data;
		node<Type>* next;
	public:
		node(const Type &newData, node<Type> *newNext = nullptr)
			: data(newData), next(newNext)
		{
		}
};

// node structure to contain data. I used it bc more comfortable with struct
struct Node{
    string data;
    Node *next;
};

// stack class filled up
template <class Type>
class Stack
{
private:
    // stack top item node
    Node *top;

	public:
	    // constructor
		Stack()
		{
		    top = NULL;
		}
		// constructor with a reference
		Stack(const Stack &other)
		{
            Stack *s = new Stack();
            Stack *r = new Stack();

            while(!s->empty)
            {
                string replacement = s->pop();
                r->push(replacement);
            }

            while(!r->empty)
            {
                string replacement = r->pop();
                other->push(replacement);
            }


		}
		// = operator
		const Stack& operator=(const Stack &rhs)
		{
		    string copyy;

		    while (!rhs.empty())
            {
                copyy = rhs->pop();
                this->push(copyy);
            }

		}
		// dectructor to clear memory
		virtual ~Stack()
		{
            while (!empty())
            {
                pop();
            }

		}

		// to check if stack is empty or no
		bool empty() const
		{
            return (top == NULL);
		}
		std::size_t size() const;

		// to add values to the top of the stack
		void push(const Type &value)
		{
            // create new node to store data.
            Node *temp = new Node;
            temp->data = value;
            temp->next = top;

            top = temp;
		}

		// to pop off value at the top of the stack
		string pop()
		{
            if(!empty())
                {
                    string value = top->data;
                    Node *oldtop = top;
                    top = oldtop->next;
                    delete oldtop;
                    return value;
                }
            else
                {
                    cout << "You can't pop empty stack! " << endl;
                    exit(1);
                }
		}
		// prints the stack
		string toString()
        {
            string result = "(top) -> ";
            if(empty())
            {
                result = result + "NULL";
                return result;
            }
            else
            {
                Node *current = top;
                while (current != NULL)
                {
                    result = result + current->data + " -> ";
                    current = current->next;
                }
                result = result + "(END)";
                return result;
            }
        }
        // debug function
		void debug() const;
		void debug(std::ostream &out) const;
};

// debug function
template <class Type>
void Stack<Type>::debug() const
{
	debug(std::cout);
}

// debug function with reference

template <class Type>
void Stack<Type>::debug(std::ostream &out) const
{
    int count;

    Node *current = top;
                while (current != NULL)
                {
                    current->data;
                    current = current->next;
                }

    Node *firstNode = top;

	out << "Number of items in stack: " << count << std::endl;
	out << "Top of stack is node @"  << firstNode << std::endl;

	node<Type> *next = firstNode;

	while (next != nullptr)
	{
		out << "@" << next << ", next @" << next->next << ", data = " << next->data << std::endl;
		next = next->next;
	}
}

#endif /* STACK_H_ */
