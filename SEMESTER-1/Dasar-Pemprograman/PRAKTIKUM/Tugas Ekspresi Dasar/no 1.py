"""
Diberikan masukan berupa waktu yang terdiri atas jam berupa integer[0..24], menit berupa
integer [0..59], dan detik berupa integer [0..59]. Buatlah sebuah program untuk mengkonversi
sebuah waktu tersebut ke dalam satuan detik terhitung mulai waktu 00:00:00 pada tanggal
yang bersangkutan.
"""

def timetosecond (h : int, m : int, s : int):
    return (h * 60 * 60) + (m * 60) + s
print(timetosecond(13, 58, 20))