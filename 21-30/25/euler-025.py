def fibonnaciSeries():
    fn1 = 1
    fn2 = 1

    for i in range(10000):
        fn = fn1 + fn2
        temp = fn1
        fn1 = fn
        fn2 = temp 
        if (len(str(fn)) == 1000): 
            print(i+3)
            print(fn)
            break    
         

def main():
    fibonnaciSeries()

if __name__ == '__main__':
    main()