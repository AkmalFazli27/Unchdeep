"""
Program   : Perpustakaan Agung
Deskripsi : Program ini menghitung estimasi jumlah pengunjung di Perpustakaan Agung berdasarkan prediksi dari tiga ahli (Ahli Statistika, Ahli Matematika, dan Ahli Ilmu Perpustakaan) serta data historis pengunjung pada hari tertentu. Perhitungan akan mempertimbangkan waktu siang dan malam dengan faktor pengali untuk waktu malam.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 23/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI

TabelHari : string -> float
{TabelHari(Hari) mengembalikan rata-rata jumlah pengunjung pada hari yang ditentukan berdasarkan data 
historis. Parameter:
Hari (string): Nama hari dalam seminggu ("senin", "selasa", "rabu", "kamis", "jumat", "sabtu", "minggu"). Fungsi ini akan mengembalikan rata-rata jumlah pengunjung (float) untuk hari yang diberikan.}

EstimateGreatLib : string, int, int, int, int, int, int, int, int → float
{EstimateGreatLib(D, X, Y, SS, SR, AS, AM, AIP, R) menghitung estimasi perbandingan jumlah pengunjung 
dari Perpustakaan Agung berdasarkan parameter berikut:
    1. D (string): Hari yang akan diperkirakan ("senin", "selasa", "rabu", "kamis", "jumat", "sabtu", "minggu").
    2. X (int): Jam mulai perkiraan (0 ≤ X ≤ 24).
    3. Y (int): Jam akhir perkiraan (X < Y ≤ 24).
    4. SS (int): Jam matahari terbenam (0 ≤ SS ≤ 24).
    5. SR (int): Jam matahari terbit (0 ≤ SR ≤ 24).
    6. AS (int): Prediksi jumlah pengunjung dari Ahli Statistika (0 ≤ AS ≤ 10000).
    7. AM (int): Prediksi jumlah pengunjung dari Ahli Matematika (0 ≤ AM ≤ 10000).
    8. AIP (int): Prediksi jumlah pengunjung dari Ahli Ilmu Perpustakaan (0 ≤ AIP ≤ 10000).
    9. R (int): Persentase pengali untuk estimasi malam (1 ≤ R ≤ 100).
Fungsi ini akan mengembalikan estimasi perbandingan pengunjung dalam format desimal dengan maksimal 5 digit 
angka di belakang koma.}
"""

# REALISASI
def pekan_sebelumnya (D):
    if D == "senin":
        return (5000 + 6000 + 4000) / 3
    elif D == "selasa":
        return (7000 + 5000 + 2000) / 3
    elif D == "rabu":
        return (4500 + 3500 + 3000) / 3
    elif D == "kamis":
        return (2900 + 2100 + 2000) / 3
    elif D == "jumat":
        return (3000 + 3000 + 3000) / 3
    elif D == "sabtu":
        return (2000 + 2500 + 2300) / 3
    elif D == "minggu":
        return (1100 + 900 + 1000) / 3

def range (AS, AM, AIP):
    return max(AS, AM, AIP) - min(AS, AM, AIP)

def EstimateGreatLib(D, X, Y, SS, SR, AS, AM, AIP, R):
    # full siang
    if X >= SR and Y <= SS:
        return round(((Y - X) * range (AS, AM, AIP) / pekan_sebelumnya (D)), 5)
    
    # full malam
    if X >= SS and Y >= SS:
        return round(((Y - X) * range (AS, AM, AIP) / pekan_sebelumnya (D)) * R / 100, 5)
    
    # buka sebelum terbit dan tutup setelah terbit, tapi tutup sebelum tenggelam
    if X < SR and Y > SR and Y <= SS:
        return round(((range (AS, AM, AIP) / pekan_sebelumnya (D) * (SR - X) * R/100) + (range (AS, AM, AIP) / pekan_sebelumnya (D) * (Y - SR))) / 2, 5)
    
    # buka sebelum terbenam dan tutup setelah terbenam
    if X >= SR and Y > SS and Y > X and X < SS:
        return round(((range (AS, AM, AIP) / pekan_sebelumnya (D) * (Y - SS) * R/100) + (range (AS, AM, AIP) / pekan_sebelumnya (D) * (SS -X))) / 2, 5)
    
    # buka sebelum terbit dan tutup setelah terbenam
    if X < SR and Y > SS:
        round(((range (AS, AM, AIP) / pekan_sebelumnya (D) * (SR - X) * R/100) + (range (AS, AM, AIP) / pekan_sebelumnya (D) * (Y - SS)) + (range (AS, AM, AIP) / pekan_sebelumnya (D) * (SS - SR))) / 3, 5)
    

# APLIKASI
print(EstimateGreatLib("jumat", 7, 8, 17, 6, 4000, 5500, 5000, 3))
print(EstimateGreatLib("senin", 12, 17, 18, 9, 6000, 5000, 4500, 50))
print(EstimateGreatLib("selasa", 8, 16, 20, 12, 7000, 5000, 2000, 75))
