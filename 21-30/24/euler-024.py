from itertools import permutations

def main():
    perm = permutations([0,1,2,3,4,5,6,7,8,9])
    
    for (index, i) in enumerate(list(perm)):
        if (index == 999999): 
            print("".join(str(x) for x in i))

    return 

if __name__ == '__main__':
    main()