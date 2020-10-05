// Assignment 2 for CS 1337.013
// Programmer: <Muhammad Khizar>

// Description: This program takes a file name and opens a file.
// After the file is opened it reads the contents and stores the number
// of questions, questions themselves and answer choices for those questions
// along with the right answer. It then runs and generates questions for 2 players
// the two players each answer half questions each. After each set of 2 questions
// their answers are shown as right or wrong. When all questions have been answered
// the scores are displayed out of 100% and the total game mean is displayed.

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "TriviaGame.h"

using namespace std;

int j = 1;

int main()
{
    // Sending the name of file to the trivia game constructor

    TriviaGame test("triviaGame1.txt");

    // declaring variables

    int userAnswer;
    int totalQuestions = test.numberOfQuestions;
    bool check;
    bool check2;

    // displaying start

    startGame();

    // for loop to keep going till all questions are answered.

    for (int i = 0; i < totalQuestions; i++)
    {

        // player 1 question answer

        cout << "\nQuestion # " << j << " for player 1" << endl;
        test.displayQuestion(i);
        test.displayAnswers(i);
        cin >> userAnswer;
        check = test.player1score(i, userAnswer);

        i++;

        // player 2 question answer

        cout << "\nQuestion # " << j << " for player 2" << endl;
        test.displayQuestion(i);
        test.displayAnswers(i);
        cin >> userAnswer;
        check2 = test.player2score(i, userAnswer);

        // calling function to check answer

        checkAns(check, check2, j);

        j++;

    }

    // displaying end result

    test.endResult();

    // deleting dynamically allocated array

    test.deletearray();

    return 0;
}
