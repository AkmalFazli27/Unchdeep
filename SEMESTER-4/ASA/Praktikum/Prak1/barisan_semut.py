def barisan_semut():
    x, y, n = map(int, input().strip().split())
    output = [x]
    num = x + 1
    
    while len(output) != n:
        if (num % y != 0) and (num % x == 0):
            output.append(num)
            num += 1
        else:
            num += 1
            continue
    print(*output)
        
    
barisan_semut()