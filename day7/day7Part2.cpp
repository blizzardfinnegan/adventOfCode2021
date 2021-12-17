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
    long int    fuelCost        = 0;
    int         fuelAdd         = 0;
    long int    bestFuelCost    = 9999999999999;
    ifstream readFile ("data/input.txt", ios::in);

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
        tempInt = 0;
        // Iterate through all crabs
        for (int i = 0; i < currentPosition.size(); i++)
        {
            fuelAdd = 0;
            // Add fuel cost for each crab
            tempInt = abs( currentPosition.at(i) - testFinalPosition );
            for (int j = 0; j <= tempInt; j++)
            {
                fuelAdd += j;
            }
            fuelCost += fuelAdd;
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
