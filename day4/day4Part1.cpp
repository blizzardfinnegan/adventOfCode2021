#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int arrayDimension = 1000;
int inputLineCount = 500;
int main (void)
{
    string rawInput;
    vector<int> ballRolls;
    bool firstLine = true;
    bool breakLoop = false;
    vector<int> boardValues;
    vector<int> bestMarkedNumbers;
    vector<int> bestBoard;
    bool boardMarks[5][5] = {};
    vector<int> markedNumbers;
    int  turnCount = 0;
    string tempString;
    int  tempInt = 0;
    int  lineCount = 0;
    int  lastCalled = 0;
    int  unmarkedNumbersSum = 0;
    ifstream readFile ("data/input.txt", ios::in);

    // Set lowest turn count overly high initially
    int  lowestTurnCount = 99999;

    // Read file into arrays
    // Putting the whole thing in a while loop probably isn't great...
    // might fix later
    while(getline(readFile, rawInput))
    {
        // Make reading the file easier by re-turning the string into a stream
        stringstream inputStream(rawInput);

        //Only the first line of the input is CSV
        if (firstLine)
        {
            // CSV Handling
            // (If copy-pasting to later, remember stringstream)
            while (getline(inputStream, tempString, ','))
            {
                tempInt = stoi(tempString);
                ballRolls.push_back(tempInt);
            }
            firstLine = false;
        }

        // ignore blank lines
        else if (rawInput.empty()) continue;

        else
        {
            lineCount++;
            while (getline(inputStream, tempString, ' '))
            {
                if (tempString == "") continue;
                else tempInt = stoi(tempString);
                boardValues.push_back(tempInt);
            }
        }

        // If there's 5 lines, then board is full.
        // Start comparing
        if(lineCount == 5)
        {
            for (turnCount = 0; turnCount < ballRolls.size(); turnCount++)
            {
                // If the board has won, exit for loop
                if(breakLoop) break;

                // Iterate through board
                for(int i = 0; i < 5; i++)
                {
                    for(int j = 0; j < 5; j++)
                    {
                        // If the number rolled is the on the board, mark it
                        // and add it to the list of marked values
                        if(boardValues.at(i*5+j) == ballRolls.at(turnCount))
                        {
                            boardMarks[i][j] = true;
                            markedNumbers.push_back(ballRolls.at(turnCount));
                        }
                    }
                }

                // Board check
                for (int i = 0; i < 5; i++)
                {
                    // Row check
                    if(boardMarks[i][0] 
                    && boardMarks[i][1]
                    && boardMarks[i][2] 
                    && boardMarks[i][3] 
                    && boardMarks[i][4])
                    {
                        breakLoop = true;
                    }

                    // column check
                    if(boardMarks[0][i] 
                    && boardMarks[1][i]
                    && boardMarks[2][i] 
                    && boardMarks[3][i] 
                    && boardMarks[4][i])
                    {
                        breakLoop = true;
                    }
                }
            }
            // If its the lowest turn count, save the board
            if(turnCount < lowestTurnCount)
            {
                lowestTurnCount = turnCount;
                bestBoard = boardValues;
                bestMarkedNumbers = markedNumbers;
            }

            // If its not the lowest turn count, reset marked numbers
            else
            {
                markedNumbers.clear();
            }
            for(int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    boardMarks[i][j]=0;
                }
            }
            boardValues.clear();
            lineCount = 0;
            breakLoop = false;
            continue;
        }
    }

    // At this point, We have found the fastest winning board
    // Now, to calculate the points

    markedNumbers = bestMarkedNumbers;
    // Iterate through board
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            // Iterate through marked numbers
            for (turnCount = 0; turnCount < markedNumbers.size(); turnCount++)
            {
                // If the number rolled is the on the board, mark it again
                if(bestBoard.at(i*5+j) == markedNumbers.at(turnCount))
                {
                    boardMarks[i][j] = true;
                }
            }
        }
    }

    cout << endl << "Marked Numbers: ";
    for (int i = 0; i < markedNumbers.size(); i++)
    {
        cout << markedNumbers[i] << ", ";
    }
    cout << endl;

    // Find and remember the last-called number
    lastCalled = markedNumbers[markedNumbers.size()-1];
    cout << "Last Called: " << lastCalled << "\t";

    // find and remember sum of unmarked numbers
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            // If the number rolled is the on the board, mark it
            // and add it to the list of marked values
            if(!(boardMarks[i][j]))
            {
               unmarkedNumbersSum += bestBoard.at(i*5+j); 
            }
        }
    }
    cout << "Unmarked Sum: " << unmarkedNumbersSum << "\t";

    cout << "Final Value: " << (unmarkedNumbersSum * lastCalled) << endl;

    return 0;
}
