#include <iostream>
#include <cmath>

using namespace std;

int main(){
    const unsigned int maxDivisors = 500;
    unsigned int index = 1;
    unsigned int count = 0;
    unsigned int triangle = 0; // triangle = index * (index+1)/2
    

  while (count <= maxDivisors)
  {
    count = 0 ;
    index = index +1;
    triangle = triangle + index;
    unsigned int sqrtNo = sqrt(triangle);
    for(unsigned int i = 1 ; i <= sqrtNo ; i++){
      if(triangle % i == 0) count= count +2;
    }
    if(triangle = sqrtNo * sqrtNo) count--;
  }
    
  cout << triangle << endl;

}