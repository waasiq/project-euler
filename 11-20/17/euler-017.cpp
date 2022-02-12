#include <iostream>

using namespace std;

string convertUnit(char);
string convertTen(char);
string tenIdentifier(string);

string funnel(string str){
    string finalChain = "";

    if(str.length() == 1)  return convertUnit(str[0]);
    else if(str.length() == 2)
    {
        string unit = convertUnit(str[1]);
        char ten = str[0];
        
        string tens;
        if(ten == '1')
        {
            tens = tenIdentifier(str);
        }
        else tens = convertTen(str[0]);
        
        finalChain += tens;
        if(unit != "zero" && ten != '1'){
            finalChain += ' ';
            finalChain += unit;
        } 
    }
    else if(str.length() == 3)
    {
        string unit = convertUnit(str[2]);
        char ten = str[1];
        string hundred = convertUnit(str[0]) + " " + "hundred";

        string tens;
        if(ten == '1')
        {
            string twoDigit = string(1,str[1]) + string(1,str[2]);
            tens = tenIdentifier(twoDigit);
        }
        else tens = convertTen(str[1]);

        finalChain += hundred;

        if(tens != "zero") {
            finalChain += " and ";
            finalChain += tens;
        }

        if(tens == "zero" && unit != "zero"){
            finalChain += " and ";
            finalChain += unit;
            unit = "zero";
        }

        if(unit != "zero" && ten != '1'){
            finalChain += ' ';
            finalChain += unit;
        } 
    }
    else if(str.length() == 4) return "one thousand";

    return finalChain;
}

string tenIdentifier(string str)
{
    if(str[1] == '0') return "ten";
    else if(str[1] == '1') return "eleven";
    else if(str[1] == '2') return "twelve";
    else if(str[1] == '3') return "thirteen";
    else if(str[1] == '4') return "fourteen";
    else if(str[1] == '5') return "fifteen";
    else if(str[1] == '6') return "sixteen";
    else if(str[1] == '7') return "seventeen";
    else if(str[1] == '8') return "eighteen";
    else if(str[1] == '9') return "nineteen";
}

string convertTen(char ch){
    if(ch == '2') return "twenty";
    else if(ch == '3') return "thirty";
    else if(ch == '4') return "forty";
    else if(ch == '5') return "fifty";
    else if(ch == '6') return "sixty";
    else if(ch == '7') return "seventy";
    else if(ch == '8') return "eighty";
    else if(ch == '9') return "ninety";
    else if(ch == '0') return "zero";
}

string convertUnit(char ch){
    if(ch == '1') return "one";
    else if(ch == '2') return "two";
    else if(ch == '3') return "three";
    else if(ch == '4') return "four";
    else if(ch == '5') return "five";
    else if(ch == '6') return "six";
    else if(ch == '7') return "seven";
    else if(ch == '8') return "eight";
    else if(ch == '9') return "nine";
    else if(ch == '0') return "zero";
}

int numberOfLetters(string str)
{
    string finalStr = "";
    for(int i = 0 ; i < str.length() ; i++)
    {   
        if(str[i] != ' ') finalStr += str[i];
    }
    return finalStr.length();
}

int main(){

    int letters = 0;
    for(int i = 0 ; i <= 1000 ; i++)
    {
        string iString = to_string(i);
        letters += numberOfLetters(funnel(iString));  
    }

    cout << "Letters Used: " << letters << endl;
    return 0;
}