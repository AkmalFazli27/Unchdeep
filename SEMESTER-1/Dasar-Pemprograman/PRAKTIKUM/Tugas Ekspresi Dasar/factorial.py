import math

def max2 (a:int,b:int) -> int:
    return (a + b + abs(a - b)) // 2

def min2 (a:int,b:int) -> int:
    return (a + b - abs(a - b)) // 2

def faktorial (n:int,r:int) -> int:
    return (math.factorial(max2 (n,r))) / (math.factorial(min2 (n,r)) * (math.factorial(max2 (n,r) - min2(n,r))))

print(faktorial (5,7))
print(faktorial (12,10))
print(faktorial (19,20))

