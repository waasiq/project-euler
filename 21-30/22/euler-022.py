def readFile():
    f = open('p022_names.txt', 'r')
    values = f.read()
    str = values.replace('","', ' ').replace('"', '').split(' ')
    return str

def main():
    str = readFile()
    str.sort()

    totalValue = 0
    for (index, name) in enumerate(str):
        charValue = 0
        for char in name:
            charValue += ord(char) - 64
        totalValue += charValue * (index + 1)
    
    print(totalValue)

if __name__ == '__main__':
    main()