/*
Solved by Waasiq Masood on 18-Oct-20. 
!!!Code is copyrighted and is not allowed to be copied.

This problem took about 9 hours to solve due to a bix of complex algorithm I 
tried.

My approach: Take the whole 20x20 grid as a string in order to generalize the 
problem for nxn grid. The 20x20 grid can be divided in matrice of 4x4 as the 
due to taking the adjacent 4 elements. Two things to notice:
1) Highest product from left to right == highest product from right to left
2) Highest product from up to down == highest product from down to up.

What I did is to break the string into grid of 20x4. Meaning 4 columns with 20 rows.
We break the 20 columns for 4x4 grid, compute the highest product and return it to 
main function. Similarly a single row is shifted and computed. After all the
rows are computed we shift one column and again compute the 20x4 grid from top to 
bottom in this way computing all the grid.
*/
#include <iostream>
#include <string>
using namespace std;

int extractHighest(string); //extracts the highest product from 4x4 matrice

int main()
{
    string str = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";
    string subStr;
    int iterator = 0, higestProduct = 0, returnedValue = 0;

    //THE FIRST LOOP HERE SHIFTS THE ARRAY HORIZONTALLY BY 3 (2 DIGITS AND 1 SPACE)
    for (int k = 0; k < 50; k += 3)
    {
        // SECOND LOOP LOOPS FROM ABOVE TO BELOW
        for (int i = 0; i < str.length(); i += 60)
        {
            //THIRD LOOP LOOPS FOR 4 ELEMENTS FROM LEFT TO RIGHT
            for (int j = 0; j < 11; j++)
            {
                int index = i + j + k;
                subStr.push_back(str[index]);
            }
            subStr.push_back(' ');

            if (iterator == 3)
            {
                iterator--;
                returnedValue = extractHighest(subStr);

                if (returnedValue > higestProduct)
                    higestProduct = returnedValue;

                subStr.erase(0, 12);
            }
            iterator++;
        }
        subStr = "";
        iterator = 0;
    }

    cout << "Highest product: " << higestProduct << endl;
    system("pause");
    return 0;
}

int extractHighest(string str)
{
    int grid[4][4] = {};
    string subStr;
    int gridX = 0, gridY = 0, iterator = 0;
    int LEFTproduct = 0, DOWNproduct = 0, RIGHT_DIAGONALproduct = 0, LEFT_DIAGONALproduct = 0;
    int highestAdjacentProduct = 0, highestLowProduct = 0;

    // POPULATING THE GRID FROM STRING
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            subStr.push_back(str[i]);
            iterator++;
        }

        //THE REASON FOR ITERATOR ==2 IS THAT THE GRID IS OF DOUBLE DIGIT NUMBERS
        if (iterator == 2)
        {
            if (gridX == 3)
            {
                grid[gridY][gridX] = stoi(subStr);
                gridY++;
                gridX = 0;
            }
            else
            {
                grid[gridY][gridX] = stoi(subStr);
                gridX++;
            }
            iterator = 0;
            subStr = "";
        }
    }

    //CHECKING ALL THE PRODUCTS DOWN, LEFT, DIAGONAL
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; ++j)
        {
            DOWNproduct == 0 ? DOWNproduct += grid[j][i] : DOWNproduct *= grid[j][i];
            LEFTproduct == 0 ? LEFTproduct += grid[i][j] : LEFTproduct *= grid[i][j];

            if (i == j)
            {
                LEFT_DIAGONALproduct == 0 ? LEFT_DIAGONALproduct += grid[i][j] : LEFT_DIAGONALproduct *= grid[i][j];
            }
            if (i + j == 3)
            {
                RIGHT_DIAGONALproduct == 0 ? RIGHT_DIAGONALproduct += grid[i][j] : RIGHT_DIAGONALproduct *= grid[i][j];
            }
        }

        if (LEFTproduct > highestAdjacentProduct)
        {
            highestAdjacentProduct = LEFTproduct;
        }
        else if (DOWNproduct > highestLowProduct)
        {
            highestLowProduct = DOWNproduct;
        }

        LEFTproduct = 0, DOWNproduct = 0;
    }

    // RETURNING THE HIGHEST VALUE
    if (highestAdjacentProduct > highestLowProduct &&
        highestAdjacentProduct > LEFT_DIAGONALproduct &&
        highestAdjacentProduct > RIGHT_DIAGONALproduct)
    {
        return highestAdjacentProduct;
    }
    else if (highestLowProduct > highestAdjacentProduct &&
             highestLowProduct > LEFT_DIAGONALproduct &&
             highestLowProduct > RIGHT_DIAGONALproduct)
    {
        return highestLowProduct;
    }
    else if (LEFT_DIAGONALproduct > highestAdjacentProduct &&
             LEFT_DIAGONALproduct > highestLowProduct &&
             LEFT_DIAGONALproduct > RIGHT_DIAGONALproduct)
    {
        return LEFT_DIAGONALproduct;
    }
    else
    {
        return RIGHT_DIAGONALproduct;
    }
}
