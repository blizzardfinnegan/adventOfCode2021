#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    int lastValue = 0;
    int currentValue = 0;
    int decreaseCount = 0;
    cout << "test\n";
    ifstream readFile ("data/input.txt", ios::in);

    while(readFile >> currentValue)
    {
        if (lastValue != 0)
        {
            if (lastValue < currentValue) decreaseCount++;
            cout << decreaseCount << "\n";
        }
        lastValue = currentValue;
    }
    cout << decreaseCount;
    return 0;
}
