#include "drinkmachine.h"

using namespace std;

bool create(DrinkMachine &drinkMachine)
{
    ifstream inputFile;
    inputFile.open("drink_machine.txt");

    if(inputFile.fail())
    {
        return false;
    }
    else
    {
        inputFile >> drinkMachine.totalDrinks;

        int i = 0;

        while(inputFile >> drinkMachine.arrayDrink[i].name >> drinkMachine.arrayDrink[i].price >> drinkMachine.arrayDrink[i].NumDrinksOfSameType)
        {
            drinkMachine.arrayDrink[i].id = i + 1;
            i++;
        }

        inputFile.close();
        return true;
    }

}

void destroy(DrinkMachine &drinkMachine)
{
    ofstream outputFile;
    outputFile.open("drink_machine.txt");

    outputFile << drinkMachine.totalDrinks << endl;

    for(int i = 0; i < drinkMachine.totalDrinks; i++)
    {
        outputFile << setw(22) << left << drinkMachine.arrayDrink[i].name << setprecision(2) << fixed << drinkMachine.arrayDrink[i].price
        << setw(3) << right << drinkMachine.arrayDrink[i].NumDrinksOfSameType << endl;
    }

    drinkMachine.totalDrinks = 0;

    outputFile.close();
}

DrinkItem& drink(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    return drinkMachine.arrayDrink[drinkId - 1];
}

unsigned int size(DrinkMachine &drinkMachine)
{
    return drinkMachine.totalDrinks;
}

bool available(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    int id = drinkMachine.arrayDrink[drinkId - 1].NumDrinksOfSameType;

    if (id > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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

string name(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    if (drinkId < 0 || drinkId > drinkMachine.totalDrinks)
    {
        return "invalid";
    }
    else
    {
        return drinkMachine.arrayDrink[drinkId - 1].name;
    }

}

unsigned int quantity(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    if ((drinkId < 0) || (drinkId > drinkMachine.totalDrinks))
    {
        return 0;
    }
    else
    {
        return drinkMachine.arrayDrink[drinkId - 1].NumDrinksOfSameType;
    }
}

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

bool purchase(DrinkMachine &drinkMachine, int unsigned drinkId, double amount, double &change)
{
    if(amount < drinkMachine.arrayDrink[drinkId - 1].price)
    {
        return false;
    }
    else
    {
        change = amount - drinkMachine.arrayDrink[drinkId - 1].price;
        (drinkMachine.arrayDrink[drinkId - 1].drinksPurchased)++;
        (drinkMachine.arrayDrink[drinkId - 1].NumDrinksOfSameType)--;
        return true;
    }
}
