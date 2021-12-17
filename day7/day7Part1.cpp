#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main (void)
{
    int         tempInt         = 0;
    string      rawInput;
    vector<int> currentPosition;
    int         maxPosition     = 0;
    int         bestPosition    = 0;
    int         fuelCost        = 0;
    int         bestFuelCost    = 999999999;
    ifstream readFile ("data/testInput.txt", ios::in);

    // CSV Handling; creates vector of ints
    while(getline(readFile, rawInput, ','))
    {
        tempInt = stoi(rawInput);
        currentPosition.push_back(tempInt);
    }

    // Find and mark max Position
    maxPosition = *max_element(currentPosition.begin(), currentPosition.end());

    // Iterate through all possible final locations
    for (int testFinalPosition = 0; testFinalPosition < maxPosition; testFinalPosition++)
    {
        fuelCost = 0;
        // Iterate through all crabs
        for (int i = 0; i < currentPosition.size(); i++)
        {
            // Add fuel cost for each crab
            fuelCost += abs( currentPosition.at(i) - testFinalPosition );
        }

        if (fuelCost < bestFuelCost) 
        {
            bestFuelCost = fuelCost;
            bestPosition = testFinalPosition;
        }
    }
    cout << "Best Fuel cost: "<< bestFuelCost << "\t";
    cout << "Pos. of Best Fuel cost: " << bestPosition << endl;
    return 0;
}
