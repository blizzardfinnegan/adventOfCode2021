#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void)
{
    int lineSize = 100; //100 for input
    string rawInput;
    string tempString;
    vector<int>  heightMap;
    vector<bool> basinBarrier;
    int     index = 0;
    vector<int> lowPointIndexes;
    int     totalRisk = 0;
    ifstream readFile ("data/input.txt", ios::in);

    // Pull file into RAM
    while(getline(readFile, rawInput))
    {
        for (int i = 0; i < rawInput.size(); i++)
        {
            heightMap.push_back((rawInput[i] - 48));
        }
    }

    // Iterate through map
    for (index = 0; index < heightMap.size(); index++)
    {
        if (index == 0)
        {
            if (
                    heightMap.at(index) < heightMap.at(index + 1) &&
                    heightMap.at(index) < heightMap.at(index + lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else if (index < lineSize)
        {
            if (
                    heightMap.at(index) < heightMap.at(index + 1) &&
                    heightMap.at(index) < heightMap.at(index - 1) &&
                    heightMap.at(index) < heightMap.at(index + lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else if ((index % lineSize) == (lineSize - 1))
        {
            if (
                    heightMap.at(index) < heightMap.at(index - 1) &&
                    heightMap.at(index) < heightMap.at(index - lineSize) &&
                    heightMap.at(index) < heightMap.at(index + lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else if (index  == (lineSize - 1))
        {
            if (
                    heightMap.at(index) < heightMap.at(index - 1) &&
                    heightMap.at(index) < heightMap.at(index + lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else if ((index % lineSize) == 0)
        {
            if (
                    heightMap.at(index) < heightMap.at(index + 1) &&
                    heightMap.at(index) < heightMap.at(index - lineSize) &&
                    heightMap.at(index) < heightMap.at(index + lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else if (index  == (heightMap.size() - lineSize - 1))
        {
            if (
                    heightMap.at(index) < heightMap.at(index + 1) &&
                    heightMap.at(index) < heightMap.at(index - lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else if ((index / lineSize) == ((heightMap.size() - 1) / lineSize))
        {
            if (
                    heightMap.at(index) < heightMap.at(index + 1) &&
                    heightMap.at(index) < heightMap.at(index - 1) &&
                    heightMap.at(index) < heightMap.at(index - lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else if (index  == (heightMap.size() - 1))
        {
            if (
                    heightMap.at(index) < heightMap.at(index - 1) &&
                    heightMap.at(index) < heightMap.at(index - lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
        else
        {
            if (
                    heightMap.at(index) < heightMap.at(index + 1) &&
                    heightMap.at(index) < heightMap.at(index - 1) &&
                    heightMap.at(index) < heightMap.at(index - lineSize) &&
                    heightMap.at(index) < heightMap.at(index + lineSize)
               )
            {
                lowPointIndexes.push_back(index);
            }
        }
    }

    // All low points are now saved in lowPointIndexes as indicies
    // --------
    
    basinBarrier.reserve(heightMap.size());
    for (index = 0; index < heightMap.size();index++)
    {
        if (heightMap.at(index) == 9)
        {
            basinBarrier.at(index) = true;
        }
    }

    return 0;
}
