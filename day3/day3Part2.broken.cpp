#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <array>
using namespace std;

int main (void)
{
    vector<array<int, 5>> inputValues;
    vector<array<int, 5>> mostCommon;
    vector<array<int, 5>> mostCommonWorking;
    vector<array<int, 5>> leastCommon;
    char currentLine[5];
    array<int, 5> currentLineInt;
    int mostBitTrue[5] = {};
    int mostBitFalse[5] = {};
    int leastBitTrue[5] = {};
    int leastBitFalse[5] = {};
    int oxygenGenRatingBin[5] = {};
    int coScrubRatingBin[5] = {};
    int oxygenGenRatingDec = 0;
    int coScrubRatingDec = 0;
    int lifeSupport = 0;
    int debugCount = 0;
    int vectorSize = 0;
    ifstream readFile ("data/testInput.txt", ios::in);

    //file Read
    while(readFile >> currentLine)
    {
        for(int i=0;i<5;i++)
        {
            if (currentLine[i] == '1') currentLineInt[i] = 1;
            else if (currentLine[i] == '0') currentLineInt[i] = 0;
        }
        inputValues.push_back(currentLineInt);
    }

    mostCommon = inputValues;
    leastCommon = inputValues;


    //most Common filter
    //Iterate through all bits in line
    for(int i=0;i<5;i++)
    {
        mostCommon = mostCommonWorking;
        mostCommonWorking.clear();
        //if there's only one line, leave the loop
        if(mostCommon.size() == 1) 
        {
            cout << "Exiting mostCommon loop..." << endl;
            break;
        }

        //Iterate through all entries in mostCommon, count 1s and 0s
        for (int j=0;j<mostCommon.size();j++)
        {
            if(mostCommon[j][i] == 1) mostBitTrue[i]++;
            else if(mostCommon[j][i] == 0) mostBitFalse[i]++;
            //Error Checking
            else
            {
                cout << "Error!" << endl;
                return 1;
            }
        }
        //Balancing
        if (mostBitTrue[i] == mostBitFalse[i]) mostBitTrue[i]++;

        //If there are more 1s than 0s, save 1s
        if (mostBitTrue[i] > mostBitFalse[i])
        {
            for(int j=0;j=mostCommon.size();j++)
            {
                if(mostCommon[j][i] == 1) mostCommonWorking.push_back(mostCommon[i]);
            }
        }

        //If there are more 0s than 1s, save 0s
        if (mostBitFalse[i] > mostBitTrue[i])
        {
            for(int j=0;j=mostCommon.size();j++)
            {
                if(mostCommon[j][i] == 0) mostCommonWorking.push_back(mostCommon[i]);
            }
        }
        cout << "Most Common Working: ";
        for(int j=0;j<mostCommonWorking.size();j++)
        {
            for(int k=0;k<5;k++)
            {
                cout << mostCommonWorking[j][k];
            }
            cout << "\t";
        }
        cout << endl;
    }

    cout << "**************\nFinal Value: ";
    for(int i=0;i<5;i++) cout << mostCommon[0][i];
    cout << "\n**************\n\n" << endl;

    //*******************************************************************
    //least Common filter
    //Iterate through all bits in line
    for(int i=0;i<5;i++)
    {
        //if there's only one line, leave the loop
        if(leastCommon.size() == 1) break;

        //Iterate through all entries in leastCommon, count 1s and 0s
        for (int j=0;j<leastCommon.size();j++)
        {
            if(leastCommon[j][i] == 1) leastBitTrue[i]++;
            else if(leastCommon[j][i] == 0) leastBitFalse[i]++;
            //Error Checking
            else
            {
                cout << "Error!!" << endl;
                return 2;
            }
        }

        //Balancing
        if (leastBitTrue[i] == leastBitFalse[i]) leastBitTrue[i]++;

        //if there are more 1s than 0s
        if(leastBitTrue[i] > leastBitFalse[i])
        {
            for (int j=0;j<leastCommon.size();j++)
            {
                //remove 1s
                if(leastCommon[j][i] == 1) leastCommon.erase(leastCommon.begin() + j);
            }
        }

        //if there are more 0s than 1s
        if(leastBitFalse[i] > leastBitTrue[i])
        {
            for (int j=0;j<leastCommon.size();j++)
            {
                //remove 0s
                if(leastCommon[j][i] == 0) leastCommon.erase(leastCommon.begin() + j);
            }
        }
        debugCount = 0;
        cout << "Current leastCommon:\t";
        for(int j=0;j<leastCommon.size();j++)
        {
            for(int k=0;k<5;k++)
            {
                cout << leastCommon[j][k];
            }
            cout << "\t";
            debugCount++;
        }
        cout << "\n Value Count: " << debugCount << "\n" << endl;
    }

    cout << endl;
    for(int i=0;i<5;i++) cout << leastCommon[0][i];

    for(int i=0;i<5;i++)
    {
        if(mostCommon[0][i] == 1) oxygenGenRatingBin[i]=1;
        else if(mostCommon[0][i] == 0) oxygenGenRatingBin[i]=0;
        else
        {
            cout << "Error!!!" << endl; 
            return 3;
        }
        if(leastCommon[0][i] == 1) coScrubRatingBin[i]=1;
        else if(leastCommon[0][i] == 0) coScrubRatingBin[i]=0;
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
