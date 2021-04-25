// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
// Checking for the prime factors until number. If a prime factor is found divide the number with the prime factor.
// The reason for i*i here is to speed up the process because if a number N a prime factor larger than square of N 
//, then it surely has a prime factor smaller than square of N.

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