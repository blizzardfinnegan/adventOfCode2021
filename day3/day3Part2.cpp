#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

int i = 0;
char zeroChar = '0';

bool bitIsFalse(string binString)
{
    return (binString[i] == '0');
}

bool bitIsTrue(string binString)
{
    return (binString[i] == '1');
}

int main (void)
{
    vector<string> inputValues;
    vector<string> mostCommonList;
    vector<string>::iterator mostCommonListIt;
    vector<string> leastCommonList;
    vector<string>::iterator leastCommonListIt;
    string currentLine;
    string mostCommonFinal;
    string leastCommonFinal;
    int mostBitTrue[5] = {};
    int mostBitFalse[5] = {};
    int leastBitTrue[5] = {};
    int leastBitFalse[5] = {};
    int oxygenGenRatingBin[5] = {};
    int coScrubRatingBin[5] = {};
    int oxygenGenRatingDec = 0;
    int coScrubRatingDec = 0;
    int lifeSupport = 0;
    ifstream readFile ("data/testInput.txt", ios::in);

    //file Read
    while(getline(readFile, currentLine))
    {
        inputValues.emplace_back(currentLine);
    }

    mostCommonList = inputValues;
    leastCommonList = inputValues;


    //most Common filter
    //Iterate through all bits in line
    for(i=0;i<5;i++)
    {
        //exit loop if list only has one string
        if (mostCommonList.size() == 1) break;

        //iterate through list
        for (int j=0;j<mostCommonList.size();j++)
        {
            //increment counter
            cout << mostCommonList[j][i];
            if (mostCommonList[j][i] == '0') mostBitFalse[i]++;
            else if (mostCommonList[j][i] == '1') mostBitTrue[i]++;
            else 
            {
                cout << "Error!" << endl;
                return 1;
            }
        }

        //if same, true has priority
        if (mostBitTrue[i] == mostBitFalse[i]) mostBitTrue[i]++;

        if (mostBitTrue[i] > mostBitFalse[i]) 
        {
            mostCommonListIt = remove_if(mostCommonList.begin(), mostCommonList.end(), bitIsFalse);
        }
        if (mostBitFalse[i] > mostBitTrue[i]) 
        {
            mostCommonListIt = remove_if(mostCommonList.begin(), mostCommonList.end(), bitIsTrue);
        }
    }

    mostCommonFinal = *mostCommonList.begin();
    //*******************************************************************
    //least Common filter
    //Iterate through all bits in line
    for(i=0;i<5;i++)
    {
        //exit loop if list only has one string
        if (leastCommonList.size() == 1) break;

        //iterate through list
        for (auto it = leastCommonList.begin(); it != leastCommonList.end(); ++it)
        {
            //make index of list usable
            currentLine = *it;

            //increment counter
            if (currentLine[i] == 0) leastBitFalse[i]++;
            else if (currentLine[i] == 1) leastBitTrue[i]++;
            else 
            {
                cout << "Error!" << endl;
                return 1;
            }
        }

        //if same, true has priority
        if (mostBitTrue[i] == mostBitFalse[i]) mostBitTrue[i]++;

        if (mostBitTrue[i] > mostBitFalse[i]) 
        {
            mostCommonListIt = remove_if(mostCommonList.begin(), mostCommonList.end(), bitIsFalse);
        }
        if (mostBitFalse[i] > mostBitTrue[i]) 
        {
            mostCommonListIt = remove_if(mostCommonList.begin(), mostCommonList.end(), bitIsTrue);
        }
    }
    leastCommonFinal = *leastCommonList.begin();

    for(i=0;i<5;i++)
    {
        if(mostCommonFinal[i] == 1) oxygenGenRatingBin[i]=1;
        else if(mostCommonFinal[i] == 0) oxygenGenRatingBin[i]=0;
        else
        {
            cout << "Error!!!" << endl; 
            return 3;
        }
        if(leastCommonFinal[i] == 1) coScrubRatingBin[i]=1;
        else if(leastCommonFinal[i] == 0) coScrubRatingBin[i]=0;
        else
        {
            cout << "Error!!!!" << endl; 
            return 4;
        }
    }
    for(int i=0;i<5;i++)
    {
        oxygenGenRatingDec += oxygenGenRatingBin[i] * pow(2,04-i);
        coScrubRatingDec += coScrubRatingBin[i] * pow(2,04-i);
    }
    lifeSupport = oxygenGenRatingDec * coScrubRatingDec;
    cout << "\nLife Support Rating: " << lifeSupport;
    return 0;
}
