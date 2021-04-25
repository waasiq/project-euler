// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
// I am computing every fibonnaci number and checking if its even or not.
// placeHolder stores the last value of Fibonnaci number [F(i+1)] and assigns it to the first value [F(i)].
// The last value is computed by adding the previous value and the value before it.

#include <iostream>

using namespace std;

int main()
{
    long range = 4000000, sum = 2, placeHolder = 0, firstValue = 1, lastValue = 2;

    while (lastValue < range)
    {
        placeHolder = lastValue;
        lastValue = firstValue + lastValue;
        firstValue = placeHolder;

        if (lastValue % 2 == 0)
        {
            sum += lastValue;
        }
    }

    cout << "Sum is: " << sum << endl;

    return 0;
}