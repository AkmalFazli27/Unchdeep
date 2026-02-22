def kargo_antariksa():
    n = map(int, input().strip().split())
    berat_kotak = list(map(int, input().strip().split()))
    
    genap = sorted([x for x in berat_kotak if x % 2 == 0], reverse=True)
    ganjil = sorted([x for x in berat_kotak if x % 2 != 0], reverse=True)
    
    max_berat = -1
    
    if len(genap) >= 1 and len(ganjil) >= 2:
        if genap[0] + ganjil[0] + ganjil[1] > max_berat:
            max_berat = genap[0] + ganjil[0] + ganjil[1]
    
    if len(ganjil) >= 3:
        if ganjil[0] + ganjil[1] + ganjil[2] > max_berat:
            max_berat = ganjil[0] + ganjil[1] + ganjil[2]
            
    print(max_berat)
    
kargo_antariksa()