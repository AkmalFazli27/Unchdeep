def TagihanAir(kode,volume):
    if kode == "A":
        if volume <= 10:
            return 30000
        else:
            return 30000 + ((volume - 10) * 2500)
    if kode == "B":
        if volume <= 10:
            return 40000
        if volume > 10:
            return 40000 + ((volume - 10) * 3000)
    if kode == "C":
        if volume <= 10:
            return 50000
        if volume > 10:
            return 50000 + ((volume - 10) * 3500)
        
print(TagihanAir("A",25))
print(TagihanAir("B",8))
print(TagihanAir("C",30))