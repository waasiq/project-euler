// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
//  The problem bascially requires us to compute the LCM until the number 20.


#include <iostream>

using namespace std;

static unsigned long lcm(unsigned number)
{
    auto result = 1UL;
    for (auto i = 2UL; i <= number; i++)
    {
        if (result % i)
        { // i is prime
            auto x = i;
            while (x * i <= number)
                x *= i;
            result *= x;
        }
    }
    return result;
}

int main()
{
    cout << lcm(20) << endl;
    return 0;
}