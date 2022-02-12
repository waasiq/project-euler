// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
//  I am brute forcing until a specified number called range and keeping count of the prime numbers
// once the count reaches 10001 I stop the loop and print the prime number.

#include <iostream>

using namespace std;

int main()
{
    int range = 1000000, count = 0, primeNumber = 0;

    for (int i = 2; i < range; i++)
    {
        bool prime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }

        if (prime)
        {
            count++;
        }

        if (count == 10001)
        {
            primeNumber = i;
            i = range;
        }
    }

    cout << "10001'th prime number is: " << primeNumber << endl;
    return 0;
}
