// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
// sum of Squares : 1^2 + 2^2 + 3^2 + 4^2... n^2 = ((n)(n+1)(2n+1))/6
// sum of n numbers: 1+ 2+ ... + n = n(n+1) / 2

#include <iostream>

using namespace std;

int main()
{
    int sumSquare = (100 * 101 * 201) / 6;

    int sum = (100 * 101) / 2;
    int squareOfSum = sum * sum;

    int difference = (sumSquare > squareOfSum) ? sumSquare - squareOfSum : squareOfSum - sumSquare;

    cout << "Difference: " << difference << endl;
    return 0;
}