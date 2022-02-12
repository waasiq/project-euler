stringNumber = str(pow(2,1000))

sum = 0

for char in stringNumber:
    sum += int(char)

print(sum)