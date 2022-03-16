import math

def isPrime(num):
    if num == 1: return False

    for i in range(2, int(math.sqrt(num))):
        if num % i == 0 or num % (num // i) == 0: return False

    return True

maxPrimes = 0 
maxA = 0 
maxB = 0

for i in range(1000, -1000 , -1):
    for j in range(1000, -1001, -1):
        n = 0
        while (isPrime(abs(n**2 + i * n + j))):
            n += 1        
  
        if (n > maxPrimes): 
            maxPrimes = n
            maxA , maxB  = i, j

print(maxA * maxB)