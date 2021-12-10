#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main (void)
{
    string rawInput;
    int valueCounter = 0;
    int charCount = 0;
    int lineValueCounter = 0;
    bool print = false;
    ifstream readFile ("data/input.txt", ios::in);

    //Read file into arrays
    while(getline(readFile, rawInput))
    {
        charCount = 0;
        lineValueCounter = 0;
        print = false;
        for(int i=0;i<=rawInput.size();i++)
        {
            switch (rawInput[i])
            {
                case ' ':
                    if(charCount == 2 || charCount == 3 || charCount == 4 || charCount == 7)
                    {
                        if(print) cout << charCount << "\t";
                        lineValueCounter++;
                    } 
                    charCount = 0;
                    break;
                case '|':
                    print = true;
                    lineValueCounter = 0;
                    //cout << endl << "----------" << endl;
                    break;
                default:
                    charCount++;
            }
        }
        valueCounter += lineValueCounter;
        cout << endl << "*********" << endl << "Current Count: " << valueCounter << endl << "*********" << endl;
    }
    cout << valueCounter << endl;

    return 0;
}
