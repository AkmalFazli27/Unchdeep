"""
Seorang mahasiswa berhak mendapat gelar cumlaude jika masa studi tidak lebih dari 4,5 tahun
dan memiliki nilai IPK minimal 3.50. Buatlah program untuk mengecek apakah seorang
mahasiswa cumluade berdasarkan masa studi yang dinyatakan dalam bulan dan nilai IPK
dengan range [0..4].
"""
def cumlaude (tahun, ipk):
    return tahun < 4.5 and 3.5 <= ipk <= 4
print(f"Mahasiswa dinyatakan cumlaude : {cumlaude (3, 4)}")