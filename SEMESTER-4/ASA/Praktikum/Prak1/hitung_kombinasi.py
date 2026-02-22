import math
  
def hitung_kombinasi():
    string = input().strip()
    dict = {}
    x = 1
    
    for char in string:
        if char in dict:
            dict[char] += 1
        else:
            dict[char] = 1
    
    for value in dict.values():
        x *= math.factorial(value)
        
    hasil = math.factorial(len(string)) // x
    
    print(hasil)

hitung_kombinasi()