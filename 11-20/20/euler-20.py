import math

#! Author: Waasiq Masood
#! Date: 2 - Feb - 2022


def main():
    fact = str(math.factorial(100))
    
    sum = 0
    for i in range(len(fact)):
        sum += int(fact[i])

    print(sum)

if __name__ == '__main__':
    main()