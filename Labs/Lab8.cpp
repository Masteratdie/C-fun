/*
 *Course: CS215-00x
 *Project: Lab 8 (As the first part of Project 2)
 *Purpose: to implement a Gradebook Report
 *         it allows the user to repeatedly enter students' scores
 *         until the user types "q" or "Q" to quit
 *         then displays all the valid scores from user input
 *                       and the corresponding letter grades;
 *                       the average score, highest score and lowest score.
 *Author: Aaron Weitekamp, Section: 010
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "FinalGrade.h"

using namespace std;

double calculateGradebook(const vector<FinalGrade>& gradebook, double& max_score, double& min_score) {
    double avg = 0;
    min_score = gradebook.at(0).getScore();

    for (int i = 0; i < gradebook.size(); i++) {
        if (gradebook.at(i).getScore() < min_score)
            min_score = gradebook.at(i).getScore();

        if (gradebook[i].getScore() > max_score)
            max_score = gradebook.at(i).getScore();

        avg += gradebook.at(i).getScore();
    }
    return avg /= gradebook.size();
}

FinalGrade::FinalGrade(double in_score) {
    score = in_score;
}

void FinalGrade::setScore(double in_score) {
    score = in_score;
}

double FinalGrade::getScore() const
{
    return score;
}

char FinalGrade::decideLetterGrade() const
{
    if (score >= 90)
        return 'A';
    else if (score >= 80)
        return 'B';
    else if (score >= 70)
        return 'C';
    else if (score >= 60)
        return 'D';
    else if (score < 60)
        return 'E';
}

void FinalGrade::print() const
{
    cout << "Score: " << score << setw(20) << " Letter Grade: " << decideLetterGrade() << endl;
    // Score: 88.00        Letter Grade: B
}

int main()
{
    vector<FinalGrade> CS215gradebook;
    double input_score;

    while (true)
    {
        cout << "Please enter a score for CS215 (type 'Q' or 'q' to quit): " << endl;
        cin >> input_score;

        // check if the user input is invalid
        if (cin.fail())
        {
            string check_input;
            cin.clear();
            cin >> check_input;
            cin.ignore(256, '\n');  //extra and ignore any possible bad input from the input stream

            if (check_input == "Q" || check_input == "q")
                break;
            else {
                cout << "Invalid input, please try again..." << endl;
                continue;
            }
        }

        // check if the input score is in the correct range: [0,100]
        if (input_score < 0 || input_score > 100)
        {
            cout << "The score is not in the correct range, please try again..." << endl;
        }
        else  // valid user input, store into gradeList object
        {
            FinalGrade inputFG(input_score);
            CS215gradebook.push_back(inputFG);
        }

        cin.ignore(256, '\n');  //extra and ignore any possible bad input from the input stream
    }

    // Check if the gradebook is empty
    // If it is empty, report it then quit the program
    if (CS215gradebook.size() == 0)
    {
        cout << "The gradebook for CS215 is empty!" << endl;
        return 1;
    }

    // if the gradebook is not empty
    // Display each score and corresponding letter grade in the grade    
    // Display the average score, the highest and lowest scores from the gradebook
    cout << endl << endl;
    cout << "The gradebook for CS215:" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < CS215gradebook.size(); i++)
    {
        CS215gradebook[i].print();
    }

    double max_score = 0;
    double min_score = 0;
    double average = calculateGradebook(CS215gradebook, max_score, min_score);
    cout << "The average score is: " << average << endl;
    cout << "The highest score is: " << max_score << endl;
    cout << "The lowest score is: " << min_score << endl;
    return 0;
}