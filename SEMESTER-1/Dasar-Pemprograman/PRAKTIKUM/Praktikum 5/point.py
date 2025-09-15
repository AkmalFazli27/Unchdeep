import math

def fx2 (x):
    return x**2

def MakePoint (x,y):
    return [x,y]

def absis(P):
    return P[0]

def ordinat(P):
    return P[1]

def IsOrigin (P):
    return absis(P) == 0 and ordinat(P) == 0

def jarak (P1, P2):
    return math.sqrt(fx2(absis(P2) - absis(P1) + fx2(ordinat(P2) - ordinat(P1))))

def jarak0 (P):
    return math.sqrt(fx2(absis(P)) + fx2(ordinat(P)))

def kuadran (P):
    if (absis (P) > 0 and ordinat (P) > 0): return f"Titik {absis (P),ordinat(P)} berada di Kuadran 1"
    if (absis (P) < 0 and ordinat (P) > 0): return f"Titik {absis (P),ordinat(P)} berada di Kuadran 2"
    if (absis (P) < 0 and ordinat (P) < 0): return f"Titik {absis (P),ordinat(P)} berada di Kuadran 3"
    if (absis (P) > 0 and ordinat (P) < 0): return f"Titik {absis (P),ordinat(P)} berada di Kuadran 4"

P = [1,2]