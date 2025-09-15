"""
Program   : Shop Smart
Deskripsi : Program ini menghitung harga akhir barang di toko Shop Smart berdasarkan kategori produk, status keanggotaan, lokasi pembelian, dan hari transaksi. Sistem ini menerapkan diskon dinamis dan pajak sesuai dengan kebijakan toko, memberikan pelanggan harga yang paling adil dan sesuai dengan aturan promosi yang berlaku.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 23/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI

diskon : integer, float → float
{diskon(harga, persen) menghitung harga setelah penerapan diskon berdasarkan persen yang diberikan.
Fungsi ini mengembalikan harga setelah diskon sebagai float.}

pajak : integer, float → float
{pajak(harga, persen) menghitung harga setelah penambahan pajak berdasarkan persen yang diberikan.
Fungsi ini mengembalikan harga setelah pajak sebagai float.}

aturan_diskon : integer, string, boolean → float
{aturan_diskon(harga, kategori, VIP) menghitung harga setelah penerapan diskon berdasarkan kategori 
barang dan status keanggotaan.
Fungsi ini mengembalikan harga setelah penerapan diskon sebagai float.}

aturan_hari : float, string, string, boolean → float
{aturan_hari(harga, hari, kategori, VIP) menghitung harga setelah penerapan diskon atau pajak tambahan 
berdasarkan hari transaksi dan kategori barang.
Fungsi ini mengembalikan harga setelah penerapan tambahan diskon atau pajak sebagai float.}

aturan_pajak : float, string → float
{aturan_pajak(harga, lokasi) menghitung harga setelah penerapan pajak berdasarkan lokasi pembelian.
Fungsi ini mengembalikan harga setelah penerapan pajak sebagai float.}

hargaAkhir : integer, string, boolean, string, string → integer
{hargaAkhir(harga, kategori, VIP, lokasi, hari) menghitung harga akhir barang dengan mempertimbangkan 
diskon, pajak, dan aturan tambahan berdasarkan kategori barang, status keanggotaan, lokasi, dan hari 
transaksi.
Fungsi ini akan mengembalikan harga akhir barang sebagai integer yang lebih besar dari 0.}
"""

# REALISASI
def diskon (kategori,VIP):
    if kategori == "elektronik":
        if VIP == True:
            return 70 / 100
        return 90 / 100
    elif kategori == "pakaian":
        if VIP == True:
            return 80 / 100
        return 95 / 100
    elif kategori == "makanan":
        if VIP == True:
            return 85 / 100
        return 98 / 100
    elif kategori == "lainnya":
        return 100 / 100
    
def pajak (lokasi):
    if lokasi == "dalam negeri":
        return 110 / 100
    if lokasi == "luar negeri":
        return 120 / 100

def hari_beli (kategori,VIP,hari):
    if (hari == "Jumat" or hari == "Sabtu") and VIP == True:
        return 95 / 100
    if hari == "Minggu":
        return 105 / 100
    if hari == "Rabu" and kategori == "pakaian":
        return 95 / 100
    else:
        return 100 / 100

def hargaAkhir (harga, kategori, VIP, lokasi, hari):
    return (harga * diskon (kategori,VIP) * hari_beli (kategori,VIP,hari) * pajak (lokasi))


# APLIKASI
print(int(hargaAkhir(100000, "elektronik", True, "dalam negeri", "Senin")))
print(int(hargaAkhir(500000, "pakaian", False, "luar negeri", "Rabu")))