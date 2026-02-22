def pulau_angka():
    n, m = map(int, input().strip().split())
    pulau_angka = list(map(int, input().strip().split()))
    angka_musnah = set(map(int, input().strip().split()))
    
    hasil = []
    
    for angka in pulau_angka:
        if angka not in angka_musnah:
            hasil.append(angka)
    
    if len(hasil) == 0:
        print("KOSONG")
    else:
        print(*hasil)
    
pulau_angka()