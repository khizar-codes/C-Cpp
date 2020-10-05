#include <iostream>
#include <cstdlib>

using namespace std;

// create a node struct
struct Node{
    string data;
    Node *next;
};

class Stack{
public:
    Stack(); // constructor
    ~Stack(); // desetructor delete all the pointers
    void push(string d); // pushes node to top of stack
    string pop(); // pop top node off the stack
    string toString(); // display stack contents
    bool isEmpty();

private:
    Node *top;

};

Stack::Stack(){
    // initialize stack to be empty
    top = NULL;
}

Stack::~Stack(){
    // delete dynamic variables

    while (!empty())
        pop();
}

void Stack::push(string d)
{
    // create new node to store data.
    Node *temp = new Node;
    temp->data = d;
    temp->next = top;

    top = temp;
}

string Stack::pop()
{
    if(!isEmpty())
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

string Stack::toString()
{
    string result = "(top) -> ";
    if(isEmpty())
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

bool Stack::isEmpty()
{
    return (top == NULL);
}

int main()
{
    Stack *s = new Stack();

    cout << "output when s empty " << endl
    << s->toString() << endl << endl;
    s->push("CheeseBurger");
    s->push("L coff");
    s->push("pizza");
    s->pop();
    s->pop();
    cout << "output when s NOT empty " << endl
    << s->toString() << endl << endl;

    Stack *other = new Stack();

    string khizar = s->pop();
    other->push(khizar);
    other->push("sadia");
    cout << "output when s NOT empty " << endl
    << other->toString() << endl << endl;


    delete s;
    delete other;
    return 0;

}
