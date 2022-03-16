with open('./value.txt') as f:
    arr = []
    for line in f:
        arr.append(list(map(int, line.split(' '))))

#* The logic is here to start from bottom to top and adding the sum of 
#*  element below it or on its right after comparing the highest sum ofcourse.
#*  The algorithm will go from bottom to top and give you the highest sum at arr[0][0]

for i in range(len(arr) - 2, -1 , -1):
    for j in range(len(arr[i])):
        if (arr[i][j] + arr[i+1][j] > arr[i][j] + arr[i+1][j+1]):
            arr[i][j] = arr[i][j] + arr[i+1][j]
        else:
            arr[i][j] = arr[i][j] + arr[i+1][j+1]

print(arr[0][0])

