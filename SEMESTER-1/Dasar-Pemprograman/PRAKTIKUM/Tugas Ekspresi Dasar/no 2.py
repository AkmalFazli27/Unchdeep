"""
Sebuah persamaan kuadrat ax2 + bx + c = 0 mempunyai akar-akar berupa x1 dan x2. Buatlah
program untuk menghitung jumlahan kuadrat dari akar-akar persamaan kuadrat (x1^2 + x2^2)
tersebut jika diberikan nilai a, b, dan c. 
"""

def pers_kuadrat (a : int, b : int, c : int):
    return ((- b / a) ** 2) - (2 * (c / a))

print(pers_kuadrat(1, 2, 3))