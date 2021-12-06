#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main (void)
{
    char currentLine[12];
    int bitTrue[12] = {};
    int bitFalse[12] = {};
    int gammaRateBin[12] = {};
    int epsilonRateBin[12] = {};
    int gammaRateDec = 0;
    int epsilonRateDec = 0;
    int powerConsumption;
    ifstream readFile ("data/input.txt", ios::in);

    while(readFile >> currentLine)
    {
        for(int i=0;i<12;i++)
        {
            if(currentLine[i] == '0') bitFalse[i]++;
            else if(currentLine[i] == '1') bitTrue[i]++;
            else cout << "Error!!!";
        }
    }

    for(int i=0;i<12;i++)
    {
        if(bitTrue[i] > bitFalse[i]) gammaRateBin[i] = 1;
        else epsilonRateBin[i] = 1;
    }

    for(int i=0;i<12;i++)
    {
        gammaRateDec += gammaRateBin[i] * pow(2,11-i);
        epsilonRateDec += epsilonRateBin[i] * pow(2,11-i);
    }
    powerConsumption = gammaRateDec * epsilonRateDec;
    cout << "\nPower Consumption: " << powerConsumption;
    return 0;
}
