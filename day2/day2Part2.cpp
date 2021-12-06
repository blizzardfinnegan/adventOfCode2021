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
    int aim = 0;
    ifstream readFile ("data/input.txt", ios::in);
    ofstream outFile ("data/testData.txt", ios::out);

    while(readFile >> direction >> count)
    {
        switch (direction[0])
        {
            case 'f':
                totalForward += count;
                totalVertical += aim * count;
                break;
            case 'u':
                aim -= count;
                break;
            case 'd':
                aim += count;
                break;
            default:
                cout << "Error!!!";
        }
        //outFile << "Total Forward: " << totalForward << "\tAim: " << aim << "\tTotal Vertical: " << totalVertical << endl;
    }
    finalAnswer = totalVertical * totalForward;
    cout << "Final Vertical: " << totalVertical;
    cout << "\nFinal Horizontal: " << totalForward;
    cout << "\nFinal Answer: " << finalAnswer;
    return 0;
}
