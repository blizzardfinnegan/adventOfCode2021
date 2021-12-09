#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main (void)
{
    string rawInput;
    vector<short int> fishCount = {};
    vector<short int> nextFishCount;
    short int dayCount = 0;
    ifstream readFile ("data/input.txt", ios::in);

    //Read file into arrays
    while(getline(readFile, rawInput))
    {
        for(int i=0;i<rawInput.size();i++)
        {
            switch(rawInput[i])
            {
                case '1':
                    fishCount.push_back(1);
                    break;
                case '2':
                    fishCount.push_back(2);
                    break;
                case '3':
                    fishCount.push_back(3);
                    break;
                case '4':
                    fishCount.push_back(4);
                    break;
                case '5':
                    fishCount.push_back(5);
                    break;
                case '6':
                    fishCount.push_back(6);
                    break;
                case '7':
                    fishCount.push_back(7);
                    break;
                case '8':
                    fishCount.push_back(8);
                    break;
                default:
                    continue;
            }
        }
    }

    nextFishCount = fishCount;
    for(dayCount;dayCount<256;dayCount++)
    {
        for(int i=0;i<fishCount.size();i++)
        {
            if(fishCount[i] == 0)
            {
                nextFishCount[i] = 6;
                nextFishCount.push_back(8);
            }
            else nextFishCount[i]--;
        }
        cout << "New Day! Processing day " << dayCount << "..." << endl;
        fishCount = nextFishCount;
    }
    cout << "Fish Count: " << fishCount.size() << endl;
    return 0;
}
