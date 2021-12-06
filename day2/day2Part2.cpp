#include <iostream>
#include <fstream>
using namespace std;

int main (void)
{
    char direction[10];
    int count = 0;
    int totalForward = 0;
    int totalVertical = 0;
    int finalAnswer = 0;
    ifstream readFile ("data/input.txt", ios::in);

    while(readFile >> direction >> count)
    {
        switch (direction[0])
        {
            case 'f':
                totalForward += count;
                break;
            case 'u':
                totalVertical -= count;
                break;
            case 'd':
                totalVertical += count;
                break;
            default:
                cout << "Error!!!";
        }
    }
    finalAnswer = totalVertical * totalForward;
    cout << finalAnswer;
    return 0;
}
