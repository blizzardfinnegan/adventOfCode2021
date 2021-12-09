#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

int byteSize = 12;
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
    string inputValues;
    string mostCommonList;
    string mostCommonWorking;
    string leastCommonList;
    string leastCommonWorking;
    string currentLine;
    string mostCommonFinal;
    string leastCommonFinal;
    int oxygenGenRatingDec = 0;
    int coScrubRatingDec = 0;
    int lifeSupport = 0;
    ifstream readFile ("data/input.txt", ios::in);

    //file Read
    while(getline(readFile, currentLine))
    {
        byteSize = currentLine.length();
        inputValues.append(currentLine);
    }

    int mostBitTrue[byteSize] = {};
    int mostBitFalse[byteSize] = {};
    int leastBitTrue[byteSize] = {};
    int leastBitFalse[byteSize] = {};
    int oxygenGenRatingBin[byteSize] = {};
    int coScrubRatingBin[byteSize] = {};
    mostCommonList = inputValues;
    mostCommonWorking = mostCommonList;
    leastCommonList = inputValues;
    leastCommonWorking = leastCommonList;

    //most Common filter
    //Iterate through all bits in line
    for(i=0;i<byteSize;i++)
    {
        //exit loop if list only has one byte
        if (mostCommonList.size() == byteSize) break;

        //iterate through string
        for (int j=0;j<(mostCommonList.length() / byteSize);j++)
        {
            //increment counter
            if (mostCommonList[j*byteSize + i] == '0') mostBitFalse[i]++;
            else if (mostCommonList[j*byteSize + i] == '1') mostBitTrue[i]++;
            else 
            {
                return 1;
            }
        }
        //Favor 1s over 0s
        if(mostBitTrue[i] == mostBitFalse[i]) mostBitTrue[i]++;

        //If more 1s than 0s
        if (mostBitTrue[i] > mostBitFalse[i])
        {
            //iterate through string
            for (int j=(mostCommonList.length() / byteSize);j>=0;j--)
            {
                //remove byte with indexed bit of 0
                if (mostCommonList[j*byteSize + i] == '0') mostCommonWorking.erase(j*byteSize, byteSize);
            }
        }
        //If more 0s than 1s
        if (mostBitFalse[i] > mostBitTrue[i])
        {
            //iterate through string
            for (int j=(mostCommonList.length() / byteSize);j>=0;j--)
            {
                // remove byte with indexed bit of 1
                if (mostCommonList[j*byteSize + i] == '1') mostCommonWorking.erase(j*byteSize, byteSize);
            }
        }
        mostCommonList = mostCommonWorking;

        //testing block
        for (int j=0;j<(mostCommonList.length() / byteSize);j++)
        {
            cout << mostCommonList[j*byteSize] << mostCommonList[j*byteSize + 1] << mostCommonList[j*byteSize + 2] << mostCommonList[j*byteSize + 3] << mostCommonList[j*byteSize + 4] << endl;
        }
        cout << endl << "******************************" << endl;
        
    }

    cout << "Final Most Common: ";
    mostCommonFinal = mostCommonList;
    cout << mostCommonFinal << endl;
    //*******************************************************************
    //least Common filter
    //Iterate through all bits in line
    for(i=0;i<byteSize;i++)
    {
        //exit loop if list only has one byte
        if (leastCommonList.size() == byteSize) break;

        //iterate through string
        for (int j=0;j<(leastCommonList.length() / byteSize);j++)
        {
            //increment counter
            if (leastCommonList[j*byteSize + i] == '0') leastBitFalse[i]++;
            else if (leastCommonList[j*byteSize + i] == '1') leastBitTrue[i]++;
            else 
            {
                return 1;
            }
        }
        //Favor 1s over 0s
        if(leastBitTrue[i] == leastBitFalse[i]) leastBitTrue[i]++;

        //If more 1s than 0s
        if (leastBitTrue[i] > leastBitFalse[i])
        {
            //iterate through string
            for (int j=(leastCommonList.length() / byteSize);j>=0;j--)
            {
                //remove byte with indexed bit of 0
                if (leastCommonList[j*byteSize + i] == '1') leastCommonWorking.erase(j*byteSize, byteSize);
            }
        }
        //If more 0s than 1s
        if (leastBitFalse[i] > leastBitTrue[i])
        {
            //iterate through string
            for (int j=(leastCommonList.length() / byteSize);j>=0;j--)
            {
                // remove byte with indexed bit of 1
                if (leastCommonList[j*byteSize + i] == '0') leastCommonWorking.erase(j*byteSize, byteSize);
            }
        }
        leastCommonList = leastCommonWorking;

        //testing block
        for (int j=0;j<(leastCommonList.length() / byteSize);j++)
        {
            cout << leastCommonList[j*byteSize] << leastCommonList[j*byteSize + 1] << leastCommonList[j*byteSize + 2] << leastCommonList[j*byteSize + 3] << leastCommonList[j*byteSize + 4] << endl;
        }
        cout << endl << "******************************" << endl;
        
    }

    cout << "Final least Common: ";
    leastCommonFinal = leastCommonList;
    cout << leastCommonFinal << endl;

    for(i=0;i<byteSize;i++)
    {
        if(mostCommonFinal[i] == '1') oxygenGenRatingBin[i]=1;
        else if(mostCommonFinal[i] == '0') oxygenGenRatingBin[i]=0;
        else
        {
            cout << "Error!!!" << endl; 
            return 3;
        }
        if(leastCommonFinal[i] == '1') coScrubRatingBin[i]=1;
        else if(leastCommonFinal[i] == '0') coScrubRatingBin[i]=0;
        else
        {
            cout << "Error!!!!" << endl; 
            return 4;
        }
    }
    for(int i=0;i<byteSize;i++)
    {
        oxygenGenRatingDec += oxygenGenRatingBin[i] * pow(2,byteSize-1-i);
        coScrubRatingDec += coScrubRatingBin[i] * pow(2,byteSize-1-i);
    }
    lifeSupport = oxygenGenRatingDec * coScrubRatingDec;
    cout << "\nLife Support Rating: " << lifeSupport;
    return 0;
}
