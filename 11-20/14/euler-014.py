def collatzSteps(number):
    steps = 1
    while number != 1:
        if number % 2 == 0:  
            number = number/2       
        else:
            number = (number*3) +1        
        steps += 1
    return steps

highestSteps = 0
highestNumber = 0

for i in range(2,1000000):
    steps = collatzSteps(i)
    if steps > highestSteps:
       highestSteps = steps
       highestNumber = i


print(highestNumber)   