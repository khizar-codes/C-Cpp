#ifndef TRIVIAGAME_H_INCLUDED
#define TRIVIAGAME_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

// question class. Stores data for a question read in from the file by the trivia game class

class Question
{
public:
    string question, choice1, choice2, choice3, choice4;
    unsigned int actualAnswer;
    string returnAnswer(int x);

    // functions to return variables

    string returnQuestion()
    {
        return question;
    }

    int returnRightAns()
    {
        return actualAnswer;
    }

    int returnNumAns()
    {
        return 4;
    }

};

class TriviaGame
{
    public:

    // declaring and initializing variables

    string temp;
    int numberOfQuestions;
    int totalp1 = 0;
    int totalp2 = 0;
    Question *questionsArray;


    // trivia game constructor

    TriviaGame(string filename)
    {
        // display opening file

        cout << "Opening File " << filename << endl;
        cout << "****************************" << endl;

        // opening file and reading

        ifstream inputFile;
        inputFile.open(filename);

        // dynamically allocating array

        questionsArray = new Question[numberOfQuestions];


        // if else to check file opening

        if(!inputFile)
        {
            cout << "File Did Not Open" << endl;
            inputFile.close();
        }
        else
        {

            // reading file

            inputFile >> numberOfQuestions;

            for( int  i = 0; i < numberOfQuestions; ++i )
            {
                inputFile.ignore();
                getline(inputFile, questionsArray[i].question);
                getline(inputFile, questionsArray[i].choice1);
                getline(inputFile, questionsArray[i].choice2);
                getline(inputFile, questionsArray[i].choice3);
                getline(inputFile, questionsArray[i].choice4);
                inputFile >> questionsArray[i].actualAnswer;
            }

            // closing file

            inputFile.close();
        }
    }

    // returns number of questions

    int numQuestions()
    {
        return (numberOfQuestions);
    }

    // to check and update score according to player answer. FOR PLAYER 1

    int player1score(int question, unsigned int x)
    {
        if(x == questionsArray[question].actualAnswer)
        {
            totalp1++;
            return true;
        }
        else
        {
            return false;
        }
    }

    // to check and update score according to player answer. FOR PLAYER 2

    int player2score(int question, unsigned int x)
    {
        if(x == questionsArray[question].actualAnswer)
        {
            totalp2++;
            return true;
        }
        else
        {
            return false;
        }
    }

    // deleting array

    void deletearray()
    {
        delete[] questionsArray;
    }

    // returning current points for p1

    int currentPoints1()
    {
        return totalp1;
    }

    // returning current points for p2

    int currentPoints2()
    {
        return totalp2;
    }

    // functions in main.cpp that are part of this class

    void displayQuestion(int i);
    void displayAnswers(int i);
    void endResult();

};

// functions not in a class. additional for game.

void startGame();
void checkAns(bool check, bool check2, int j);


#endif // TRIVIAGAME_H_INCLUDED
