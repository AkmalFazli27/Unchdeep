def max2(a,b):
    return (a + b + abs(a-b)) / 2
def min2(a,b):
    return (a + b - abs(a-b)) / 2
print(min2(1,2))

def max3 (a,b,c):
    return max2(max2(a,b),c)
def min3 (a,b,c):
    return min2(min2(a,b),c)

def median(a,b,c):
    return a + b + c - min3(a,b,c) - max3(a,b,c)

print(median(1,2,3))
print(median(10,25,5))
print(median(150,275,325))
