#include "TriviaGame.h"

using namespace std;

// function to display start

void startGame()
    {
        cout << "This game consists of 2 players, each answering 2 questions.\n" << "The player with the most points will win the game." << endl;
    }

    // trivia game function to display end result using if else and calcualte mean

void TriviaGame::endResult()
     {
        if(totalp1 > totalp2)
        {
            cout << "Player 1 wins with " << totalp1 << " points, player 2 received " << totalp2 << " points." << endl;
        }
        else if (totalp1 < totalp2)
        {
            cout << "Player 2 wins with " << totalp2 << " points, player 1 received " << totalp1 << " points." << endl;
        }
        else
        {
            cout << "Player 1 and Player 2 tied with " << totalp1 << " each." << endl;
        }

        double avg = ((totalp1 + totalp2 * 1.0) / numberOfQuestions) * 100;

        cout << "Player 1 mean was " << (totalp1 / (numberOfQuestions / 2.0)) * 100 << "%" << endl;
        cout << "Player 2 mean was " << (totalp2 / (numberOfQuestions / 2.0)) * 100 << "%" << endl;
        cout << "Game mean was " << avg << "%" << endl;
    }

    // trivia game function to display question

    void TriviaGame::displayQuestion(int i)
    {
        cout << questionsArray[i].question << endl;
    }

    // trivia game function to display answers to a question

    void TriviaGame::displayAnswers(int i)
    {
        cout << "\nPick from the following answers:" << endl;
        cout << "A # 1: " << questionsArray[i].choice1 << endl;
        cout << "A # 2: " << questionsArray[i].choice2 << endl;
        cout << "A # 3: " << questionsArray[i].choice3 << endl;
        cout << "A # 4: " << questionsArray[i].choice4 << endl << endl;
        cout << "Enter your answer:" << endl;
    }

    // Questions class function that returns answers for number passed

    string Question::returnAnswer(int x)
    {
        if(x == 1)
        {
            return choice1;
        }
        else if (x == 2)
        {
            return choice2;
        }
        else if (x == 3)
        {
            return choice3;
        }
        else if (x == 4)
        {
            return choice4;
        }
        else
        {
            cout << "Choices are only 1-4." << endl;
        }
    }

    // normal function to check the asnwer and display right or wrong

void checkAns(bool check, bool check2, int j)
{
     if(check)
        {
            cout << "\nPlayer 1 had the correct answer for question " << j << endl;
        }
        else
        {
            cout << "\nPlayer 1 had the incorrect answer for question " << j << endl;
        }

    if(check2)
        {
            cout << "Player 2 had the correct answer for question " << j << endl << endl;
        }
        else
        {
            cout << "Player 2 had the incorrect answer for question " << j << endl << endl;
        }
}
