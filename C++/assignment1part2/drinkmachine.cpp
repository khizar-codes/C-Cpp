#include "drinkmachine.h"

using namespace std;

// create function, takes the structure and fills in the array in it with the data from the file
//returns false if file doesnt open.

bool create(DrinkMachine &drinkMachine)
{
    int totalDrinks;
    char binArray[16];
    double drinkPrice;
    int NST;
    int drinkPurchased;

    // opening input binary file

    ifstream inputFile;
    inputFile.open("drink_machine.bin" , ios::in | ios::binary);

    totalDrinks = drinkMachine.totalDrinks;

    // checking file validity

    if(inputFile.fail())
    {
        return false;
    }
    else
    {
        // inputting data

        inputFile.read(reinterpret_cast<char *>(&totalDrinks), sizeof(totalDrinks));

        for(int i = 0; i < totalDrinks; i++)
        {
            inputFile.read(inputFile.read(binArray, sizeof(binArray));
            inputFile.read(reinterpret_cast<char *>&drinkPrice, sizeof(drinkPrice));
            inputFile.read(reinterpret_cast<char *>&NST, sizeof(NST));
            inputFile.read(reinterpret_cast<char *>&drinkPurchased, sizeof(drinkPurchased));

            drinkMachine.arrayDrink[i].name = binArray;
            drinkMachine.arrayDrink[i].price = drinkPrice;
            drinkMachine.arrayDrink[i].NumDrinksOfSameType = NST;
            drinkMachine.arrayDrink[i].drinksPurchased = drinkPurchased;

        }

        // closing files

        inputFile.close();
        return true;
    }

}

// destroy function, takes in the drink machine structure and erases the data and the total drinks

void destroy(DrinkMachine &drinkMachine)
{
    // opening binary output file

    ofstream outputFile;
    outputFile.open("drink_machine.bin" , ios::in | ios::binary);

    // transferring data

    outputFile.write(&ch, sizeof(binArray));

    for(int i = 0; i < drinkMachine.totalDrinks; i++)
    {
        outputFile.write(&drinkMachine.arrayDrink[i].name, sizeof(drinkMachine.arrayDrink[i].name));
        outputFile.write(reinterpret_cast<char *>&drinkMachine.arrayDrink[i].price, sizeof(drinkMachine.arrayDrink[i].price));
        outputFile.write(reinterpret_cast<char *>&drinkMachine.arrayDrink[i].NumDrinksOfSameType, sizeof(drinkMachine.arrayDrink[i].NumDrinksOfSameType));
        outputFile.write(reinterpret_cast<char *>&drinkMachine.arrayDrink[i].drinksPurchased, sizeof(drinkMachine.arrayDrink[i].drinksPurchased));
    }

    // making total drinks 0

    drinkMachine.totalDrinks = 0;

    // closing file

    outputFile.close();
}


// This function takes in the drink machine structure and the drink id and gives back the drinnk item structure in the
// specific index of the array
DrinkItem& drink(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    return drinkMachine.arrayDrink[drinkId - 1];
}

// size function gives back the total number of drinks in the machine.

unsigned int size(DrinkMachine &drinkMachine)
{
    return drinkMachine.totalDrinks;
}

// This function takes in the user entry of the drink and checks if it is stil available. returns boolean

bool available(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    int id = drinkMachine.arrayDrink[drinkId - 1].NumDrinksOfSameType;

    // checking is drinks are available

    if (id > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// checks the price of the user choice of drink and returns the dollar amount

double price(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    if (drinkId < 0 || drinkId > drinkMachine.totalDrinks)
    {
        return -1;
    }
    else
    {
        return drinkMachine.arrayDrink[drinkId - 1].price;
    }

}

// returns the name of the drink the user wanted. invalid returned if user entry is wrong

string name(DrinkMachine &drinkMachine, unsigned int drinkId)
{

    // checking id

    if (drinkId < 0 || drinkId > drinkMachine.totalDrinks)
    {
        return "invalid";
    }
    else
    {
        return drinkMachine.arrayDrink[drinkId - 1].name;
    }

}

// quantity function returns the number of drinks of the same type in the machine
// takes in the drink machine structure and drink id.

unsigned int quantity(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    if ((drinkId < 0) || (drinkId > drinkMachine.totalDrinks))
    {
        // returns 0 if the quantity is no valid

        return 0;
    }
    else
    {
        return drinkMachine.arrayDrink[drinkId - 1].NumDrinksOfSameType;
    }
}

// this function takes in the drink machine structure and drink id
// returns 0 if id is invalid and returns the sold number of drinks
// when its right.

unsigned int sold(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    if (drinkId < 0 || drinkId > drinkMachine.totalDrinks)
    {
        return 0;
    }
    else
    {
        return drinkMachine.arrayDrink[drinkId - 1].drinksPurchased;
    }
}

// validates the purchase. called when user enters the payment. Returns boolean based on
// payment value

bool purchase(DrinkMachine &drinkMachine, int unsigned drinkId, double amount, double &change)
{
    if(amount < drinkMachine.arrayDrink[drinkId - 1].price)
    {
        return false;
    }
    else
    {
        // calculating change, incrementing and decrementing quantitiy and sold amount

        change = amount - drinkMachine.arrayDrink[drinkId - 1].price;
        (drinkMachine.arrayDrink[drinkId - 1].drinksPurchased)++;
        (drinkMachine.arrayDrink[drinkId - 1].NumDrinksOfSameType)--;
        return true;
    }
}
