"""
Program   : TYPE DATE
Deskripsi : Didefinisikan suatu type Date yang terdiri dari thari, bulan dan tahun dan membentuk komposisi <Hr,Bln,Thn>. Dalam contoh ini, sebuah nama type bukan merupakan nama type bentukan, melainkan sebuah subdomain (sebagian dari nilai domain). Penamaan semacam ini akan mempermudah pembacaan teks.
NIM/Nama  : 24060124130123/Muhammad Akmal Fazli Riyadi
Tanggal   : 30/09/2024
"""

"""
DEFINISI DAN SPESIFIKASI TYPE
type Hr : integer [1...31] 
    {Definisi ini hanyalah untuk “menamakan” type integer dengan nilai tertentu supaya mewakili hari, sehingga jika dipunyai suatu nilai integer, kita dapat memeriksa apakah nilai integer tersebut mewakili Hari yang absah } 
type Bln : integer [1...12] 
    {Definisi ini hanyalah untuk “menamakan” type integer dengan daerah nilai tertentu supaya mewakili Bulan } 
type Thn : integer > 0 
    {Definisi ini hanyalah untuk “menamakan“ type integer dengan daerah nilai tertentu supaya mewakili tahun } 
type date <d: Hr, m:Bln,y:Thn> 
    {<d,m,y> adalah tanggal d bulan m tahun y} 

DEFINISI DAN SPESIFIKASI SELEKTOR
Day : date → Hr 
    {Day (D) memberikan hari d dari D yang terdiri dari <d,m,y> } 
Month : date → Bln 
    {Month (D) memberikan bulan m dari D yang terdiri dari <d,m,y> } 
Year : date → Thn 
    {Year (D) memberikan tahun y dari D yang terdiri dari <d,m,y> }

KONSTRUKTOR
MakeDate : <Hr,Bln,Thn> → date 
    {MakeDate <(h,b,t>) → tgl pada hari,bulan,tahun yang bersangkutan }

DEFINISI DAN SPESIFIKASI OPERATOR/FUNGSI LAIN TERHADAP DATE
Nextday : date → date 
    {NextDay(D): menghitung date yang merupakan keesokan hari dari date D yang diberikan: 
            Nextday (<1,1,80>) adalah (<2,1,80>) 
            Nextday (<31,1,80>) adalah (<1,2,80> 
            Nextday (<30,4,80>) adalah (<1,5,80> 
            Nextday (<31,12,80>) adalah (<1,1,81> 
            Nextday (<28,2,80>) adalah (<29,2,80> 
            Nextday (<28,2,81>) adalah (<1,3,82> }
Yesterday : date → date 
    {Yesterday(D): Menghitung date yang merupakan 1 hari sebelum date D yang diberikan: 
            Yesterday (<1,1,80>) adalah <31,12,79> 
            Yesterday (<31,1,80>) adalah <30,1,80> 
            Yesterday (<1,5,80>) adalah <30,4,80> 
            Yesterday (<31,12,80>) adalah <30,12,80> 
            Yesterday (<29,2,80>) adalah <28,2,80> 
            Yesterday (<1,3,80>) adalah <29,2,80> } 
NextNday : date,integer [0..366] → date 
    {NextNDay(D,N) : Menghitung date yang merupakan N hari (N adalah nilai integer) sesudah dari date D yang diberikan} 
HariKe1900: date → integer [0..366] 
    {HariKe1900(D) : Menghitung jumlah hari terhadap 1 Januari pada tahun y, dengan memperhitungkan apakah y adalah tahun kabisat }

PREDIKAT
IsEqD?: 2 date → boolean
    {IsEqD?(d1,d2) benar jika d1=d2, mengirimkan true jika d1=d2 and m1=m2 and y1=y2. Contoh : EqD(<1,1,90>,<1,1,90>) adalah true EqD(<1,2,90>,<1,1,90>) adalah false} 
IsBefore? : 2 date → boolean
    {IsBefore?(d1,d2) benar e jika d1 adalah sebelum d2 mengirimkan true jika D1 adalah "sebelum" D2: 
        HariKe1900 dari D1 adalah lebih kecil dari HariKe1900 D2 } 
        {Contoh :   Before (<1,1,80>,<1,2,80>) adalah false } 
                    Before (<1,1,80>,<2,1,80>) adalah true } 
IsAfter? : 2 date → boolean
    {IsAfter?(d1,d2) benar jika d1 adalah sesudah d2 mengirimkan true jika D1 adalah "sesudah" D2: 
        HariKe1900 dari D1 adalah lebih besar dari HariKe1900 dari D2. 
        Contoh :    After (<1,11,80>,<1,2,80>) adalah true 
                    After (<1,1,80>,<2,1,80>) adalah false
                    After (<1,1,80>,<1,1,80>) adalah false} 
IsKabisat? : integer → boolean
    {IsKabisat?(a) true jika tahun 1900+a adalah tahun kabisat: habis dibagi 4 tetapi tidak habis dibagi 100, atau habis dibagi 400 }
"""

# REALISASI
def Day(date):
    return date[0]

def Month(date):
    return date[1]

def Year(date):
    return date[2]

def MakeDate(Hr, Bln, Thn):
    if Hr < 1 or Hr > 31:
        return f"Error Hr: {Hr}"
    if Bln < 1 or Bln > 12:
        return f"Error Bln: {Bln}"
    if Thn < 1:
        return f"Error Thn: {Thn}"
    return [Hr, Bln, Thn]

def NextDay(date):
    if Month(date) in [1, 3, 5, 7, 8, 10]:
        if Day(date) < 31:
            return MakeDate(Day(date) + 1, Month(date), Year(date))
        return MakeDate(1, Month(date) + 1, Year(date))
    if Month(date) in [4, 6, 9, 11]:
        if Month(date) < 30:
            return MakeDate(Day(date) + 1, Month(date), Year(date))
        return MakeDate(1, Month(date) + 1, Year(date))
    if Month(date) == 2:
        if IsKabisat(Year(date)):
            if Day(date) == 28:
                return MakeDate(Day(date) + 1, Month(date), Year(date))
            return MakeDate(1, Month(date) + 1, Year(date))
        if Day(date) < 28:
            return MakeDate(Day(date) + 1, Month(date), Year(date))
        return MakeDate(1, Month(date) + 1, Year(date))
    if Month(date) == 12:
        if Day(date) < 31:
            return MakeDate(Day(date) + 1, Month(date), Year(date))
        return MakeDate(1, 1, Year(date) + 1)

def Yesterday(date):
    if Day(date) == 1:
        if Month(date) in [5, 7, 8, 10, 12]:
            return MakeDate(30, Month(date) - 1, Year(date))
        if Month(date) in [2, 4, 6, 9, 11]:
            return MakeDate(31, Month(date) - 1, Year(date))
        if Month(date) == 1:
            return MakeDate(31, 12, Year(date) - 1)
        if Month(date) == 3:
            if IsKabisat(Year(date)):
                return MakeDate(29, 2, Year(date))
            return MakeDate(28, 2, Year(date))
    return MakeDate(Day(date) - 1, Month(date), Year(date))

def NextNDay(date, N):
    if (
        dpm(Month(date))
        + Day(date)
        - 1
        + (1 if Month(date) > 2 and IsKabisat(Year(date)) else 0)
    ) + N > (366 if IsKabisat(Year(date)) else 365):
        return HrKeDate(
            Year(date) + 1,
            (
                (
                    dpm(Month(date))
                    + Day(date)
                    - 1
                    + (1 if Month(date) > 2 and IsKabisat(Year(date)) else 0)
                )
                + N
                - (366 if IsKabisat(Year(date)) else 365)
            ),
        )
    return HrKeDate(
        Year(date),
        (
            dpm(Month(date))
            + Day(date)
            - 1
            + (1 if Month(date) > 2 and IsKabisat(Year(date)) else 0)
        )
        + N,
    )

def HrKeDate(Thn, TotalHr):
    if TotalHr <= 31:
        return MakeDate(TotalHr, 1, Thn)
    if TotalHr <= (31 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - 31, 2, Thn)
    if TotalHr <= (62 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (31 + (29 if IsKabisat(Thn) else 28)), 3, Thn)
    if TotalHr <= (92 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (62 + (29 if IsKabisat(Thn) else 28)), 4, Thn)
    if TotalHr <= (123 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (92 + (29 if IsKabisat(Thn) else 28)), 5, Thn)
    if TotalHr <= (153 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (123 + (29 if IsKabisat(Thn) else 28)), 6, Thn)
    if TotalHr <= (184 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (153 + (29 if IsKabisat(Thn) else 28)), 7, Thn)
    if TotalHr <= (215 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (184 + (29 if IsKabisat(Thn) else 28)), 8, Thn)
    if TotalHr <= (245 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (215 + (29 if IsKabisat(Thn) else 28)), 9, Thn)
    if TotalHr <= (276 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (245 + (29 if IsKabisat(Thn) else 28)), 10, Thn)
    if TotalHr <= (306 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (276 + (29 if IsKabisat(Thn) else 28)), 11, Thn)
    if TotalHr <= (337 + (29 if IsKabisat(Thn) else 28)):
        return MakeDate(TotalHr - (306 + (29 if IsKabisat(Thn) else 28)), 12, Thn)

def dpm(bulan: int) -> int:
    if bulan == 1:
        return 1
    if bulan == 2:
        return 32
    if bulan == 3:
        return 60
    if bulan == 4:
        return 91
    if bulan == 5:
        return 121
    if bulan == 6:
        return 152
    if bulan == 7:
        return 182
    if bulan == 8:
        return 213
    if bulan == 9:
        return 244
    if bulan == 10:
        return 274
    if bulan == 11:
        return 305
    if bulan == 12:
        return 335

def IsKabisat(y: int) -> bool:
    return (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0)

def HariKe1900(d: int, m: int, y: int) -> int:
    return dpm(m) + d - 1 + (1 if m > 2 and IsKabisat(y) else 0)

def IsEqD(D1, D2):
    return Day(D1) == Day(D2) and Month(D1) == Month(D2) and Year(D1) == Year(D2)

def IsBefore(D1, D2):
    return (
        Day(D1) < Day(D2)
        or (Day(D1) == Day(D2) and Month(D1) < Month(D2))
        or (Day(D1) == Day(D2) and Month(D1) == Month(D2) and Year(D1) < Year(D2))
    )

def IsAfter(D1, D2):
    return (
        Day(D1) > Day(D2)
        or (Day(D1) == Day(D2) and Month(D1) > Month(D2))
        or (Day(D1) == Day(D2) and Month(D1) == Month(D2) and Year(D1) > Year(D2))
    )

# APLIKASI
print(f"NextDay: <27,4,2024> -> {NextDay(MakeDate(27, 4, 2024))}")
print(f"Yesterday: <2,2,2024> ->{Yesterday(MakeDate(2, 2, 2024))}")
print(f"IsEqD: <12,5,2024>, <12,5,2024> -> {IsEqD(MakeDate(12, 5, 2024), MakeDate(12, 5, 2024))}")
print(f"IsBefore: <1,7,2024>, <2,7,2024> -> {IsBefore(MakeDate(1, 7, 2024), MakeDate(2, 7, 2024))}")
print(f"IsAfter: <21,11,2024>, <21,1,2024> -> {IsAfter(MakeDate(21, 11, 2024), MakeDate(21, 1, 2024))}")
print(f"IsKabisat: 2024 -> {IsKabisat(2024)}")
print(f"NextNDay: <30,11,2023>, 50 -> {NextNDay(MakeDate(30, 11, 2023), 50)}")
