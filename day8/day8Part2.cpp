#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
    string rawInput;
    string tempString;
    vector<string> outputValues;
    vector<string> tempOutput;
    int digitCount = 0;
    ifstream readFile ("data/input.txt", ios::in);
    while (getline(readFile, rawInput)) 
    {
        stringstream inputStream(rawInput);
        while(getline(inputStream, tempString, ' '))
        {
            tempOutput.push_back(tempString);

            // Clear out input values
            if(tempString == "|")
            {
                tempOutput.clear();
            }
        }

        // Add sanitized input to inputs
        for (int i = 0; i < tempOutput.size(); i++)
        {
            outputValues.push_back(tempOutput[i]);
        }
    }

    for (int i = 0; i < outputValues.size(); i++)
    {
        switch ((outputValues.at(i)).size())
        {
            case 2:
            case 3:
            case 4:
            case 7:
                digitCount++;
        }
    }

    cout << "Recognizable digits: " << digitCount;
    return 0;
}
