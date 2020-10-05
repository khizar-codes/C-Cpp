#include "PhoneBook.cpp"
#include "PhoneEntry.cpp"

using namespace std;

int main()
{
    PhoneBook newBook(10);

    newBook.add("khizar", 9724649509);
    newBook.add("waqas", 9724648782);
    newBook.add("sadia", 2145241637);
    newBook.add("shahid", 2145243691);

    std::cout << "\n";

    for(int i = 0; i < newBook.getSize(); i++)
    {
        std::cout << newBook[i] << endl;
    }

    std::cout << "\n\n";

    book.remove(PhoneEntry("khizar","9724649509"));

    for(int i = 0; i < newBook.getSize(); i++)
    {
        std::cout << newBook.phoneEntryAt(i)<< endl;
    }

    std::cout << "\n\n";

    book.removeByName("sadia");
    book.removeByNumber("2145243691");

    for(int i = 0; i < newBook.getSize(); i++)
    {
        std::cout << newBook.phoneEntryAt(i)<<endl;
    }

}
