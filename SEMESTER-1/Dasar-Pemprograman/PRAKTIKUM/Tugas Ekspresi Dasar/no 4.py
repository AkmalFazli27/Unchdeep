"""
Buatlah sebuah program untuk mengecek apakah sebuah tahun merupakan tahun kabisat.
Sebuah tahun dinyatakan kabisat jika angka tahun tersebut memenuhi salah satu syarat berikut:
◦ Angka tahun habis dibagi 400, atau
◦ Angka tahun habis dibagi 4, tetapi tidak habis dibagi 100.
Contoh:
Tahun 2000 adalah tahun kabisat
Tahun 1996 adalah tahun kabisat
Tahun 1900 bukan tahun kabisat
"""
def kabisat (tahun : int)->bool:
    return tahun % 400 == 0 or tahun % 4 == 0 and tahun % 100 != 0
print(kabisat (2000))
print(kabisat (1996))
print(kabisat (1900))