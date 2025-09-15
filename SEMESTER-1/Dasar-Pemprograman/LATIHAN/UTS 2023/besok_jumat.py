def IsTomorrowFriday (d, m, y): 
    if Harike1900(d + 1,m,y) % 7 == 5 : return True
    return False

def is_kabisat(y):
    return y % 400 == 0 or y % 4 == 0 and y % 100 != 0

def Harike1900 (d,m,y):
    return dpm (m) + d - (0 if m > 2 and is_kabisat(y) else 1)

def dpm (b):
    if b == 1:
        return 1
    elif b == 2:
        return 32  
    elif b == 3:
        return 60  
    elif b == 4:
        return 91  
    elif b == 5:
        return 121  
    elif b == 6:
        return 152  
    elif b == 7:
        return 182  
    elif b == 8:
        return 213  
    elif b == 9:
        return 244  
    elif b == 10:
        return 274  
    elif b == 11:
        return 305  
    elif b == 12:
        return 335

print(IsTomorrowFriday (4,1,2018))
print(IsTomorrowFriday (13,7,2018))
print(IsTomorrowFriday (27,12,2018))