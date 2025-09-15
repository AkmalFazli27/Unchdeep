import math

def x1 (a,b,c):
    return (-b + math.sqrt(b**2 - 4*a*c)) / 2*a
def x2 (a,b,c):
    return (-b - math.sqrt(b**2 - 4*a*c)) / 2*a

def kuadrat (a, b, c):
    if x1 (a,b,c) > x2 (a,b,c):
        return x1 (a,b,c) / x2 (a,b,c)
    else:
        return x2 (a,b,c) / x1 (a,b,c)


