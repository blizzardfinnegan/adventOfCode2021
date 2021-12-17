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

    cout << endl << "Low Indexes: ";
    for (int i = 0; i < lowPointIndexes.size(); i++)
    {
        cout << lowPointIndexes.at(i) << "\t";
    }
    cout << endl;
    // All low points are now saved in lowPointIndexes as indicies
    // --------
    // Calculate Risk
    
    int counter = 0;
    for (index = 0; index < heightMap.size(); index++)
    {
        for (counter = 0; counter < lowPointIndexes.size(); counter++)
        {
            if (index == lowPointIndexes.at(counter))
            {
                totalRisk += 1 + heightMap[index];
                cout << heightMap[index] << ", ";
            }
        }
    }
    cout << "Total Risk: " << totalRisk;
    return 0;
}
