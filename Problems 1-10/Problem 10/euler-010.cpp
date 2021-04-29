// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
// Calculating prime numbers until range and adding them to sum. j*j is for optimization as explained in 
// problems before.

#include <iostream>

using namespace std;

int main()
{
    unsigned long long range = 2000000;
    unsigned long long sum = 0;
    bool isPrime;

    for (unsigned long long i = 2; i < range; i++)
    {
        isPrime = true;
        for (unsigned long long j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            sum += i;
        }
    }

    cout << "Sum of prime numbers below 2 million is: " << sum << endl;
    return 0;
}