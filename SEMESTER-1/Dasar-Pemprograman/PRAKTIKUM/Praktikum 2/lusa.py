"""
Apakah lusa hari kamis jika diberi inputan (d,m,y) jika tanggal 1 januari
hari sabtu dengan memerhatikan tahun kabisat
"""
def harike1900 (d  : int, m : int, y : int) -> int: 
    return dpm(m) + d  - ( 0 if is_kabisat(y) and m > 2 else 1) 

def hari (d, m, y):
    if harike1900 (d + 1, m, y) % 7 == 5:
        return True
    return False
    
def is_kabisat(y : int) -> bool:
    return y % 400 == 0 or y % 4 == 0 and y % 100 != 0

def dpm (b : int) -> int :
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
    
print(hari (4,1,2018))
print(hari (13,7,2018))
print(hari (27,12,2018))