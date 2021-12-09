#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int arrayDimension = 10;//1000;
int inputLineCount = 10;//500;
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
    ifstream readFile ("data/testInput.txt", ios::in);

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

    for(int index=0;index<inputLineCount;index++)
    {
        if(x1[index]==x2[index])
        {
            if(y1[index] < y2[index]) 
            {
                for(int j=y1[index];j<=y2[index];j++) map[j][x1[index]]++;
            }
            else if(y2[index] < y1[index]) 
            {
                for(int j=y2[index];j<=y1[index];j++) map[j][x1[index]]++;
            }
                
        }
        else if(y1[index]==y2[index])
        {
            if(x1[index] < x2[index]) for(int j=x1[index];j<=x2[index];j++) map[y1[index]][j]++;
            else if(x2[index] < x1[index]) for(int j=x2[index];j<=x1[index];j++) map[y1[index]][j]++;
        }
        else
        {
            if(x1[index] < x2[index]) 
            {
                for (int i=x1[index];i<x2[index];i++)
                {
                    if(y1[index] < y2[index]) 
                    {
                        for(int j=y1[index];j<=y2[index];j++) map[j][i]++;
                    }
                    else if(y2[index] < y1[index]) 
                    {
                        for(int j=y2[index];j<=y1[index];j++) map[j][i]++;
                    }
                }
            }
            else if(x2[index] < x1[index]) 
            {
                for (int i=x2[index];i<x1[index];i++)
                {
                    if(y1[index] < y2[index]) 
                    {
                        for(int j=y1[index];j<=y2[index];j++) map[j][i]++;
                    }
                    else if(y2[index] < y1[index]) 
                    {
                        for(int j=y2[index];j<=y1[index];j++) map[j][i]++;
                    }
                }
            }
        }
    }

    for(int i=0;i<arrayDimension;i++)
    {
        for(int j=0;j<arrayDimension;j++)
        {
            cout << map[j][i];
            if(map[j][i>1])overlapCount++;
        }
        cout << endl;
    }
    
    cout << overlapCount << endl;

    return 0;
}
