// # Solved by
// Waasiq Masood
// August 2020
//
// # Algorithm
// Using brute force approach for this too. NOTE TO SELF: Please try other algorithms rather
// than brute forcing these poor problems. Anyways, I am using three loops each starting less than the value
// of previous one. The if statement checks the condition of Pythagorean triplet. 

#include <iostream>

using namespace std;

int main()
{
    for (int c = 0; c < 1000; c++)
    {
        for (int b = 0; b < c; b++)
        {
            for (int a = 0; a < b; a++)
            {
                if (a + b + c == 1000 && ((a * a + b * b) == c * c))
                {
                    cout << "abc is: " << a * b * c << endl;
                    goto END;
                }
            }
        }
    }

END:
    cout << "End of program" << endl;
    return 0;
}