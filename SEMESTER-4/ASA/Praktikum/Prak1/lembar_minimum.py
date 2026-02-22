def lembar_minimum():
    uang = int(input().strip())
    uang_lembar = [50, 25, 10, 5, 1]
    total_lembar = 0
    
    for i in uang_lembar:
        total_lembar = total_lembar + (uang // i)
        uang = uang % i
    
    print(total_lembar)

lembar_minimum()