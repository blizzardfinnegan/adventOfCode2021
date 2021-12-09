#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int arrayDimension = 1000;
int inputLineCount = 500;
int main (void)
{
    int map[arrayDimension][arrayDimension] = {};
    string rawInput;
    int x1[inputLineCount] = {};
    int x2[inputLineCount] = {}; 
    int y1[inputLineCount] = {}; 
    int y2[inputLineCount] = {};
    string comma = ",";
    string arrow = " -> ";
    int lineNumber = 0;
    int overlapCount = 0;
    ifstream readFile ("data/input.txt", ios::in);

    //Read file into arrays
    while(getline(readFile, rawInput))
    {
        size_t x1End = rawInput.find(comma);
        x1[lineNumber] = stoi(rawInput.substr(0,x1End));
        size_t y1End = rawInput.find(arrow);
        y1[lineNumber] = stoi(rawInput.substr(x1End+1,y1End));
        size_t x2End = rawInput.find(comma, y1End);
        x2[lineNumber] = stoi(rawInput.substr(y1End+4,x2End));
        size_t y2End = rawInput.length()-1;
        y2[lineNumber] = stoi(rawInput.substr(x2End+1,y2End));
        lineNumber++;
    }

    for(int i=0;i<inputLineCount;i++)
    {
        if(x1[i]==x2[i])
        {
            if(y1[i] < y2[i]) for(int j=y1[i];j<=y2[i];j++) map[j][x1[i]]++;
            else if(y2[i] < y1[i]) for(int j=y2[i];j<=y1[i];j++) map[j][x1[i]]++;
        }
        if(y1[i]==y2[i])
        {
            if(x1[i] < x2[i]) for(int j=x1[i];j<=x2[i];j++) map[y1[i]][j]++;
            else if(x2[i] < x1[i]) for(int j=x2[i];j<=x1[i];j++) map[y1[i]][j]++;
        }
    }

    for(int i=0;i<arrayDimension;i++)
    {
        for(int j=0;j<arrayDimension;j++)
        {
            if(map[i][j]>1)overlapCount++;
        }
    }
    
    cout << overlapCount << endl;

    return 0;
}
