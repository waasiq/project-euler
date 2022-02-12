def factorialCalc(n):
    product = 1
    for i in range(n,1,-1):
        if n==0:
            break
        product *= n
        n-=1
    
    return product

def NCRCalc(n,r):
    return factorialCalc(n)/(factorialCalc(r) * factorialCalc(n-r))

print(NCRCalc(40,20))



