// Assignment 1 Part 1 for CS 1337.013
// Programmer: <Muhammad Khizar>

// Description: This program simulates a vending machine. It basically takes
// data from an input file which includes: Total Drinks, Different Types of drinks, prices
// of the drinks, and quantities of the drinks. It displays a menu and then it asks the
// user to choose a drink and pay for it until they press 0, aka, say no to getting drinks.
// It keeps record of the number of drinks sold and the total sales in $. After all of that is
// done and the user gets out.. The drink machine writes out data to the same file and updates
// it. And then it destroys itself.

#include "drinkmachine.h"
#include "drinkmachine.cpp"

using namespace std;

int main()
{
    // These are the variables for the transaction and user input.

    double totalSales = 0;
    int userInput;
    double payment;
    double change;

    // Drink machine instances

    DrinkMachine dm;
    DrinkMachine duplicate;
    DrinkMachine temp;

    // creating machine

    create(dm);

    // displaying data extracted from file in create

    dumpDrinkMachine(dm);

    // do while loop to keep going till user enters 0

    do
    {
        // displaying menu asking for user input

        displayMenu(dm);
        cin >> userInput;

        // if else based on user input and to validate entry

        if (userInput == 0)
        {
            cout << "The drink machine sales were $" << totalSales << endl << endl;
        }
        else
        {
            // while loop to get the right entry

            while(userInput < 0 || userInput > dm.totalDrinks)
            {
                cout << "The drink you requested is not valid" << endl;
                displayMenu(dm);
                cin >> userInput;
            }

            // keeps going if user doesnt quit

            if (!userInput == 0)
            {
                // calling available to check if drink is available

                bool worked = false;
                worked = available(dm, userInput);

                if(worked)
                {
                    // displaying cost and asking for payment

                    cout << "The " << name(dm, userInput) << " you are requesting costs $"
                     << setprecision(2) << fixed << price(dm, userInput) << endl;

                    cout << "Enter the payment amount for the drink: $";
                    cin >> payment;

                    // validating payment

                    if ((payment <= 0 || payment > 5) || (payment < price(dm, userInput)))
                    {
                        while ((payment <= 0) || (payment > 5) || (payment < price(dm, userInput)))
                        {
                            // re prompting user to enter payment

                            if ((payment <= 0) || (payment > 5))
                            {
                                cout << "The payment amount must be between $0.00 and $5.00" << endl;
                                cout << "The " << name(dm, userInput) << " you are requesting costs $" << price(dm, userInput) << endl;
                                cin >> payment;
                            }
                            if(payment < price(dm, userInput))
                            {
                                cout << "The payment amount is less than the cost of the drink" << endl;
                                cout << "The " << name(dm, userInput) << " you are requesting costs $" << price(dm, userInput) << endl;
                                cin >> payment;
                            }

                        }

                    }

                    // if purchase works and everything goes smooth machine takes money and transaction is complete

                        bool worked2 = true;

                        worked2 = purchase(dm, userInput, payment, change);

                        if(worked2 == true)
                        {
                            // displaying change

                            cout << "Your change is $" << change << endl;
                            totalSales += price(dm, userInput);
                        }



                }
                else
                {
                    // if the drink is 0 then there is a message telling the drink is out of stock

                    cout << "The drink you chose is sold out, Please make another selection" << endl;

                }
            }
        }

    }
    while (!userInput == 0);

    // Making a duplicate drink machine array to sort by purchase later

    for (int i = 0; i < dm.totalDrinks; i++)
    {
        duplicate.arrayDrink[i].id = dm.arrayDrink[i].id;
        duplicate.arrayDrink[i].name = dm.arrayDrink[i].name;
        duplicate.arrayDrink[i].price = dm.arrayDrink[i].price;
        duplicate.arrayDrink[i].NumDrinksOfSameType = dm.arrayDrink[i].NumDrinksOfSameType;
        duplicate.arrayDrink[i].drinksPurchased = dm.arrayDrink[i].drinksPurchased;
    }

    // bubble sort to display most sold drinks first and the rest last. ASCENDING ORDER

    int iteration;
    int index;
    for (iteration = 1; iteration < dm.totalDrinks; iteration++)
    {
        for (index = 0; index < dm.totalDrinks - iteration; index++)
            if (duplicate.arrayDrink[index].drinksPurchased < duplicate.arrayDrink[index + 1].drinksPurchased)
            {
                // swapping values of array

                temp.arrayDrink[index] = duplicate.arrayDrink[index];
                duplicate.arrayDrink[index] = duplicate.arrayDrink[index + 1];
                duplicate.arrayDrink[index + 1] = temp.arrayDrink[index];
            }


    }

    // displaying data one last time in ascending order

    cout << setw(10) << right << "Drink Id" << setw(14) << right << "Drink" << setw(9)
         << right << "Cost" << setw(11) << "Quantity" << setw(9) << right << "Sold" << endl;

    for(int k = 0; k < dm.totalDrinks; k++)
    {
        cout << setw(10) << right << duplicate.arrayDrink[k].id << setw(14) << right << duplicate.arrayDrink[k].name << setw(9)
             << right << duplicate.arrayDrink[k].price << setw(11) << duplicate.arrayDrink[k].NumDrinksOfSameType << setw(9)
             << right << duplicate.arrayDrink[k].drinksPurchased << endl;
    }

    // destroying the machine and storing data in the txt file.

    destroy(dm);

    return 0;
}
