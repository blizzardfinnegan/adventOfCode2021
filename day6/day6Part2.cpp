#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main (void)
{
    string rawInput;
    long int fishCount[9] = {};
    long int nextFishCount[9] = {};
    int dayCount = 0;
    long int finalFishCount = 0;
    ifstream readFile ("data/input.txt", ios::in);

    //Read file into arrays
    while(getline(readFile, rawInput))
    {
        for(int i=0;i<rawInput.size();i++)
        {
            switch(rawInput[i])
            {
                case '1':
                    fishCount[1]++;
                    break;
                case '2':
                    fishCount[2]++;
                    break;
                case '3':
                    fishCount[3]++;
                    break;
                case '4':
                    fishCount[4]++;
                    break;
                case '5':
                    fishCount[5]++;
                    break;
                case '6':
                    fishCount[6]++;
                    break;
                case '7':
                    fishCount[7]++;
                    break;
                case '8':
                    fishCount[8]++;
                    break;
                default:
                    continue;
            }
        }
    }

    cout << "Initial Size: ";
    for(int i=0;i<9;i++)
    {
        cout << fishCount[i] << ",";
    }

    for(dayCount;dayCount<256;dayCount++)
    {
        //cout << "New Day! Processing day " << dayCount << "..." << endl;
        for(int i=0;i<8;i++)
        {
            nextFishCount[i] = fishCount[i+1];
        }
        nextFishCount[8]  = fishCount[0];
        nextFishCount[6] += fishCount[0];
        for(int i=0;i<9;i++)
        {
            fishCount[i] = nextFishCount[i];
        }
    }

    cout << endl << "End Size: ";
    for(int i=0;i<9;i++)
    {
        cout << fishCount[i] << ",";
        finalFishCount += fishCount[i];
    }
    cout << "Fish Count: " <<  finalFishCount << endl;
    return 0;
}
