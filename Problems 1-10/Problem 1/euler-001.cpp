// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
// Currently I am using a brute force methodology using modulus operator.
//
// # Alternative
// An alternative way to code this would be looking into triangular numbers.  

#include <iostream>

using namespace std;

int main()
{
    int sum = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    cout << "Sum is: " << sum << endl;

    return 0;
}