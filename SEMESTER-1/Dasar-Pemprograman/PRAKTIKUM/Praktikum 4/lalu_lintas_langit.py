"""
Program   : Lalu Lintas Langit
Deskripsi : Program ini memonitor status operasional pesawat berdasarkan ketinggian, kecepatan, dan status bahan bakar. Pesawat akan diberikan status tertentu seperti "Aman untuk Mendarat", "Kecepatan Berbahaya", "Terlalu Tinggi", "Bahan Bakar Rendah", atau "Berjalan Normal".
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 23/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI

monitor_pesawat : integer [0..∞], integer [0..∞], integer [0..100] → string
{monitor_pesawat(x, y, z) memonitor kondisi pesawat berdasarkan tiga parameter utama:
    1. Ketinggian pesawat x dalam satuan meter (m).
    2. Kecepatan pesawat y dalam kilometer per jam (km/h).
    3. Status bahan bakar pesawat z dalam persen (%).
    Berdasarkan kondisi yang diberikan, fungsi ini akan mengembalikan status operasional pesawat.
    }
"""

# REALISASI
def monitor_pesawat (x,y,z):
    if (y > 900) or (y < 200):
        return "Kecepatan Berbahaya"
    if x > 12000:
        return "Terlalu Tinggi"
    if z < 20:
        return "Bahan Bakar Rendah"
    if x < 5000 and 200 < y < 900 and z > 50:
        return "Aman untuk Mendarat"
    else:
        return "Berjalan Normal"

# APLIKASI
print(monitor_pesawat(4000,850,55))
print(monitor_pesawat(5000,950,70))