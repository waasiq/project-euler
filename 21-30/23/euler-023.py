from math import sqrt

def divisors(n):
    divs = [1]
    for i in range(2, int(sqrt(n))+1):
            if n%i == 0:
                divs.extend([i,n/i])
    
    return list(set(divs))

def abudantNumbers():
    numbers = []
    for i in range(12, 28123):
        if (sum(divisors(i)) > i): numbers.append(i)    
    return numbers

def findNonSums():
    nonABNum = [x for x in range(28123)]
    ABNum = abudantNumbers()
    
    for i in range(len(ABNum)):
        for j in range (i, 28123):   
            if ABNum[i] + ABNum[j] < 28123:
                nonABNum[ABNum[i] + ABNum[j]] = 0
            else:
                break
    print(sum(nonABNum))

def main():
    findNonSums()
    
    
if __name__ == '__main__':
    main()