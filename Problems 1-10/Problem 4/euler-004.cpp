// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
//  I am using the brute force methodology to solve this problem. I am checking the result if it's
//  palindrome or not. If it's palindrome then it is stored in the largest palindrome. 


#include <iostream>

using namespace std;

bool isPalindrome(int);

int main()
{
    int result = 0, largestPalindrome = 0;
    bool checkPalindrome;

    for (int i = 100; i <= 999; i++)
    {
        for (int j = 100; j <= i; j++)
        {
            result = i * j;
            checkPalindrome = isPalindrome(result);

            if (largestPalindrome < result && checkPalindrome)
                largestPalindrome = result;
        }
    }

    cout << "Largest Palindrome is: " << largestPalindrome << endl;
    
    return 0;
}

bool isPalindrome(int num)
{
    int rev = 0; // the reversed number
    int x = num;  // store the default value (it will be changed)
    while (x > 0)
    {
        rev = 10 * rev + x % 10;
        x /= 10;
    }

    return num == rev; // returns true if the number is palindrome
}