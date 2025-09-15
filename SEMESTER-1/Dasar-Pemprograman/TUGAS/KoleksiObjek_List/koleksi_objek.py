from list_praktikum7 import *

def MakeMhs(nim,nama,kelas,nilai):
    return [nim,nama,kelas,nilai]

def NIM(mhs):
    return mhs[0]

def Nama(mhs):
    return mhs[1]

def Kelas(mhs):
    return mhs[2]
    
def Nilai(mhs):
    return mhs[3]

def RataNilai(nilai):
    if IsEmpty(nilai):
        return 0
    return SumElmt(nilai) // NbElmt(nilai)

def SetMhs(mhs):
    if IsEmpty(mhs):
        return []
    else:
        if IsMember(NIM(FirstElmt(mhs)),Tail(mhs)):
            return Tail(mhs)
        return Konso(FirstElmt(mhs),SetMhs(Tail(mhs)))
    
def MhsLulus(SetMhs):
    if IsEmpty(SetMhs):
        return []
    else:
        if RataNilai(Nilai(FirstElmt(SetMhs))) < 70:
            return MhsLulus(Tail(SetMhs))
        return Konso(FirstElmt(SetMhs),MhsLulus(Tail(SetMhs)))

def MhsTidakKuis(kelas,SetMhs):
    if IsEmpty(SetMhs):
        return []
    else:
        if kelas == Kelas(FirstElmt(SetMhs)) and Nilai(FirstElmt(SetMhs)) == []:
            return Konso(FirstElmt(SetMhs),MhsTidakKuis(kelas,Tail(SetMhs)))
        return MhsTidakKuis(kelas,Tail(SetMhs))

def NilaiTertinggiSemua(SetMhs):
    if IsEmpty(SetMhs):
        return []
    else:
        if IsOneElmt(SetMhs):
            return MaxElmt(Nilai(FirstElmt(SetMhs)))
        return max2(MaxElmt(Nilai(FirstElmt(SetMhs))),NilaiTertinggiSemua(Tail(SetMhs)))
    
def NilaiTertinggiKelas(kelas,SetMhs):
    if IsEmpty(SetMhs):
        return []
    else:
        if IsOneElmt(SetMhs):
            return SetMhs

def BanyakTidakKuis(SetMhs):
    if IsEmpty(SetMhs):
        return 0
    else:
        if Nilai(FirstElmt(SetMhs)) == []:
            return 1 + BanyakTidakKuis(Tail(SetMhs))
        return BanyakTidakKuis(Tail(SetMhs))
    
def BanyakLulus(SetMhs):
    if IsEmpty(SetMhs):
        return 0
    else:
        if RataNilai(Nilai(FirstElmt(SetMhs))) < 70:
            return BanyakLulus(Tail(SetMhs))
        return 1 + BanyakLulus(Tail(SetMhs))

print(
    NilaiTertinggiKelas(
        "A",
        SetMhs(
            [
                MakeMhs("001", "Budi", "A", [88, 75, 92]),
                MakeMhs("002", "Siti", "B", [60, 58]),
                MakeMhs("003", "Agus", "A", []),
                MakeMhs("004", "Rina", "C", [85, 90, 78]),
                MakeMhs("005", "Dewi", "B", [72, 65, 80]),
                MakeMhs("006", "Toni", "A", [50, 60, 40]),
                MakeMhs("007", "Mira", "A", []),
                MakeMhs("008", "Rudi", "C", [100, 95, 90]),
                MakeMhs("009", "Linda", "D", [55, 65]),
                MakeMhs("010", "Rahmat", "A", [95, 98, 99]),
                MakeMhs("011", "Fahmi", "B", []),
                MakeMhs("123", "Kemal", "A", [90, 69, 90]),
                MakeMhs("2001", "Zaki", "E", [85, 80, 92]),
                MakeMhs("3001", "Faris", "F", [45, 55, 60]),
                MakeMhs("5001", "Alvin", "G", [92, 94, 96]),
                MakeMhs("9999", "Nina", "H", [72, 80, 88]),
            ]
        ),
    )
)

print(
    BanyakLulus(
        SetMhs(
            [
                MakeMhs("001", "Budi", "A", [88, 75, 92]),
                MakeMhs("002", "Siti", "B", [60, 58]),
                MakeMhs("003", "Agus", "A", []),
                MakeMhs("004", "Rina", "C", [85, 90, 78]),
                MakeMhs("005", "Dewi", "B", [72, 65, 80]),
                MakeMhs("006", "Toni", "A", [50, 60, 40]),
                MakeMhs("007", "Mira", "D", []),
                MakeMhs("008", "Rudi", "C", [100, 95, 90]),
                MakeMhs("009", "Linda", "D", [55, 65]),
                MakeMhs("010", "Rahmat", "A", [95, 98, 99]),
                MakeMhs("011", "Fahmi", "B", []),
                MakeMhs("123", "Kemal", "A", [90, 69, 90]),
                MakeMhs("2001", "Zaki", "E", [85, 80, 92]),
                MakeMhs("3001", "Faris", "F", [45, 55, 60]),
                MakeMhs("5001", "Alvin", "G", [92, 94, 96]),
                MakeMhs("9999", "Nina", "H", [72, 80, 88]),
            ]
        )
    )
)