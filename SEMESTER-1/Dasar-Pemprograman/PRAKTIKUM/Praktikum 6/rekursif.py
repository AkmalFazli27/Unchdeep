# FAKTORIAL VERSI 1
def fac(n):
    if n == 1 : return 1
    else:
        return n * fac(n-1)

# FAKTORIAL VERSI 2
def fac(n):
    if n == 0 : return 1
    else:
        return n* fac(n-1)

# FIBONACCI
def fib (n):
    if n == 1 : return 1
    if n == 0 : return 0
    else:
        return fib(n-1) + fib(n-2)

from  math import factorial
x = factorial(4)

