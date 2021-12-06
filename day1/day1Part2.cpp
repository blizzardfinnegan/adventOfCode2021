#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    int lastValue = 0;
    int middleValue = 0;
    int currentValue = 0;
    int sum1 = 0;
    int sum2 = 0;
    int decreaseCount = -1;
    ifstream readFile ("data/input.txt", ios::in);

    while(readFile >> currentValue)
    {
        sum1 = lastValue + middleValue + currentValue;
        if (lastValue != 0)
        {
            if (sum2 != 0 && sum2 < sum1) 
            {
                //cout << "*++*\t";
                decreaseCount++;
            }
        }
        //cout << "Last: " << lastValue << "\tMid: " << middleValue << "\tCurrent: " << currentValue;
        //cout << "\tSum1: " << sum1 << "\tSum2: " << sum2 << "\n";
        lastValue = middleValue;
        middleValue = currentValue;
        sum2 = sum1;
    }
    cout << decreaseCount;
    return 0;
}
