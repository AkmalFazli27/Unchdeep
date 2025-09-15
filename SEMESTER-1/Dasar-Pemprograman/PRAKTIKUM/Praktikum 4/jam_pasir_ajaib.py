"""
Program   : Jam Pasir Ajaib
Deskripsi : Program ini memvalidasi input waktu dalam format jam, menit, dan detik, kemudian mencetak hasilnya dalam format yang benar atau menampilkan pesan jika waktu tidak valid.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 23/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI

jam : integer [0..24], integer [0..59], integer [0..59] → string
{jam(j,m,s) memvalidasi apakah tuple (j,m,s) merupakan waktu yang valid. Jika valid, mengembalikan string dengan format "Jam: j, Menit: m, Detik: s". Jika tidak, mengembalikan "Waktu tidak valid".}
"""

# REALISASI
def jam (j,m,s):
    if (0 <= j <= 24) and (0 <= m <= 59) and (0 <= s <= 59):
        return f"Jam: {j}, Menit: {m}, Detik: {s}"
    else:
        return "Waktu tidak valid"

# APLIKASI    
print(jam(12,30,45))
print(jam(12,45,60))