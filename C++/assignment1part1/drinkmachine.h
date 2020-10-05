/*
 * drinkmachine.h
 *
 */

#ifndef DRINKMACHINE_H_
#define DRINKMACHINE_H_

// put any includes here
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

const unsigned int maxDrinkItems = 20;

// put your structures here
struct DrinkItem
{
    unsigned int id;
    string name;
    double price;
    unsigned int NumDrinksOfSameType;
    unsigned int drinksPurchased = 0;
};

struct DrinkMachine
{
    unsigned int versionNumber = 1;
    unsigned int totalDrinks;
    DrinkItem arrayDrink[maxDrinkItems];
};



// put function prototypes here

bool create(DrinkMachine &drinkMachine);
void destroy(DrinkMachine &drinkMachine);
DrinkItem& drink(DrinkMachine &drinkMachine, unsigned int drinkId);
unsigned int size(DrinkMachine &drinkMachine);
bool available(DrinkMachine &drinkMachine, unsigned int drinkId);
double price(DrinkMachine &drinkMachine, unsigned int drinkId);
string name(DrinkMachine &drinkMachine, unsigned int drinkId);
unsigned int quantity(DrinkMachine &drinkMachine, unsigned int drinkId);
unsigned int sold(DrinkMachine &drinkMachine, unsigned int drinkId);
bool purchase(DrinkMachine &drinkMachine, int unsigned drinkId, double amount, double &change);

void displayMenu(const DrinkMachine &drinkMachine)
{
    cout << "Please enter the number of drink being purchased" << endl;
    cout << "  0 Stop processing drink orders" << endl;

    for (int i = 0; i < drinkMachine.totalDrinks; i++)
        {
            cout << setw(3) << right << drinkMachine.arrayDrink[i].id << setw(19) << right << drinkMachine.arrayDrink[i].name
            << setw(7) << right << setprecision(2) << fixed << drinkMachine.arrayDrink[i].price << endl;
        }
    cout << endl;
}

void dumpDrinkMachine(const DrinkMachine &drinkMachine)
{
    cout << "Drink Machine version " << drinkMachine.versionNumber << "\n" << endl;

    cout << setw(10) << right << "Drink Id" << setw(16) << right << "Drink" << setw(10) << right << "Cost"
    << setw(10) << right << "Quantity" << setw(10) << right << "Sold" << endl;

    for (int i = 0; i < drinkMachine.totalDrinks; i++)
    {
        cout << setw(10) << right << drinkMachine.arrayDrink[i].id << setw(16) << right
        << drinkMachine.arrayDrink[i].name << setw(10) << right << setprecision(2) << fixed << drinkMachine.arrayDrink[i].price
        << setw(10) << right << drinkMachine.arrayDrink[i].NumDrinksOfSameType << setw(10) << right
        << drinkMachine.arrayDrink[i].drinksPurchased << endl;
    }

    cout << endl;

}




// put all of your includes, structures and prototypes before this comment
#endif /* DRINKMACHINE_H_ */
