"""
Program   : Belajar Tenang
Deskripsi : Program ini menghitung jarak berdasarkan intensitas suara (dB) dan memeriksa apakah jarak tersebut melebihi batas yang ditentukan. 
            Jika jarak melebihi batas, program akan memberi peringatan untuk mengisi bensin.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 23/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI

BelajarTenang : integer, integer -> string
{BelajarTenang(dB, m) menghitung jarak berdasarkan desibel (dB) dengan rumus 15 * 10^((dB - 40) / 20) dan membandingkannya dengan nilai batas jarak m. Menghasilkan "Isi bensin dulu, bang" jika hasil perhitungan lebih besar dari m, atau mengembalikan nilai jarak tersebut dalam meter jika lebih kecil atau sama dengan m.}
"""
# REALISASI
def BelajarTenang(dB, m):
    if 15 * 10 ** ((dB - 40) / 20) >= m:
        return "Isi bensin dulu, bang"
    else:
        return f"{round(15 * 10 ** ((dB - 40) / 20),3)} meter"

# APLIKASI   
print(BelajarTenang(102, 20000))
print(BelajarTenang(100, 1300))