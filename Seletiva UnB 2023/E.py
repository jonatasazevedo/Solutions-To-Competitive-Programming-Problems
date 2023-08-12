n = int(input())

while n:
    n -= 1
    x,y = input().split("/")
    x = int(x)
    y = int(y)
    
    top = True
    while x != 0:
        d = (y+x-1)//x 
        x = x*d-y
        y = y*d
        
        if(not (top)):
            print(" + ", end='')
        else:
            top = False 
        print("1/{}".format(d), end = '')
    print()

print()
        
    
    
        