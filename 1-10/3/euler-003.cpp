// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
// Checking for the prime factors until number. If a prime factor is found divide the number with the prime factor.
// The reason for i*i here is to speed up the process.
// If a number is not prime it will have at least one divisor below (or equal to) the square root and one above (or equal to) .

#include <iostream>

using namespace std;

int main()
{
    unsigned long long number = 600851475143;

    for (unsigned long long i = 2; i*i < number; i++)
    {
        while (number % i == 0)
        {
            number = number / i;
        }
    }
    
    cout << "Largest number is: " << number;
    
    return 0;
}