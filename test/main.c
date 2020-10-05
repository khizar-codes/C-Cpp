#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


/* You will submit the following: The C program that you develop and a short description of your experiential learning while working on this project.
The second part should be about 5-10 sentences (less than 150 words) talking about what you learned and the process you used to create the game.

Script = 75 Points, Report = 25 Points */

// random number generator function, takes high and low value for range.
int randNumGenerator(int lower, int upper)
{
    // generating number
    srand(time(0));
    int randNum = lower + rand() % (upper - lower);

    // returning value
    return randNum;
}

int main()
{
    // pointer for file
    FILE * filePtr;

    // creating or opening file
    filePtr = fopen("cgame.txt", "a");

    // no file created = end program
    if(filePtr == NULL)
    {
        printf("Cannot create file.\n");
        exit(EXIT_FAILURE);
    }

    // declaring variables
    int maxValue, minValue, userInput, randomValue, totalGuesses = 1;
    bool guessed = false;

    // variable for user name
    char userName[20];

    // getting user name string
    printf("Please enter your name: ");
    scanf("%s", userName);

    // displaying & setting allowed attempts
    printf("Hello %s! You have 10 attempts to guess the random number!\n", userName);
    int allowedGuesses = 10;

    // asking for max value
    printf("\nPlease enter the max value: ");
    scanf("%d", &maxValue);

    // asking for min value
    printf("Please enter the min value: ");
    scanf("%d", &minValue);

    // getting random value from function
    randomValue = randNumGenerator(minValue, maxValue);

    // while loop to keep the program going
    while ((userInput != randomValue) && (totalGuesses <= allowedGuesses))
    {
        // getting guess from user
        printf("\nPlease enter your guess: ");

        scanf("%d", &userInput);

        // incrementing # of attempts
        totalGuesses++;

        // checking whether user guess was low, high, or correct.
        if(userInput < randomValue)
        {
            printf("Your guess was low!");
        }
        else if (userInput > randomValue)
        {
            printf("Your guess was high!");
        }
        else
        {
            // Congrats message if correct
            printf("\n**********************************************");
            printf("\nYour guess was right! The random number is %d!", randomValue);
            guessed = true;
        }


    }

    // checking whether user finished game before or after meeting the total attempts and displaying accordingly.
    if (guessed == true)
    {
        printf("\nIt took you %d guess(es)!", (totalGuesses - 1));
        printf("\n**********************************************\n");
        fprintf(filePtr, "User: %s :) You guessed it right! Your score is %d \n", userName, totalGuesses);
    }
    else
    {
        printf("\n\nSorry, you lost!\nYou could not guess the number in the allowed attempts (%d).\n", allowedGuesses);
        fprintf(filePtr, "User: %s, Sorry, you lost!\nYou could not guess the number in the allowed attempts (%d).\n", userName, allowedGuesses);
    }

    // close file
    fclose(filePtr);

    // end program
    return 0;
}
