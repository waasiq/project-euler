#include <iostream>

using namespace std;

int collatzSteps(int number){
    int steps = 1;
    while(number != 1){
        if(number % 2 == 0) {
            number = number/2;            
        }
        else {
            number = (number*3) +1;   
        }
        steps++;
    }

    return steps;
}

int main(){
    const int limit = 1000000; //1000000
    int steps = 0 , highestSteps = 0;
    int highestNumber = 0;

    for(int i = 2; i <= limit ; i++){
        steps = collatzSteps(i);

        if(steps > highestSteps){
            highestSteps = steps;
            highestNumber = i;
        }
    }

    cout << highestNumber << endl;
    cout << highestSteps << endl;
    return 0;
}