from list_praktikum7 import *

mahasiswa = [
    ["24060124120013", "Muhamad Kemal Faza", "D", [70, 80, 90]],
    ["24060124120014", "Siapa kek", "D", [60, 80, 50]],
    ["24060124120013", "Entah", "B", [80, 90, 100]],
]


def MakeMhs(nim, nama, kelas, nilai):
    return [nim, nama, kelas, nilai]


def Nim(mhs):
    return mhs[0]


def Nama(mhs):
    return mhs[1]


def Kelas(mhs):
    return mhs[2]


def Nilai(mhs):
    return mhs[-1]


def ListNilai(nilai, L):
    return [L] + nilai


def MakeSetMhs(mhs, L):
    if IsEmpty(L):
        return []
    else:
        if Nim(mhs) == Nim(FirstElmt(L)):
            return MakeSetMhs(mhs, Tail(L))
        else:
            return Konsi(mhs, L)


def MhsLulus(S):
    if IsEmpty(S):
        return []
    else:
        if AvgElmt(Nilai(FirstElmt(S))) >= 70:
            return Konso(FirstElmt(S), MhsLulus(Tail(S)))
        else:
            return MhsLulus(Tail(S))


def Pemalas(C, S):
    if IsEmpty(S):
        return []
    else:
        if Kelas(FirstElmt(S)) == C and Nilai(FirstElmt(S)) == []:
            return Konso(FirstElmt(S), Pemalas(C, Tail(S)))
        else:
            return Pemalas(C, Tail(S))


def NilaiTertinggi(S):
    if IsOneElmt(S):
        return SumElmt(Nilai(FirstElmt(S)))
    else:
        if IsEmpty(Nilai(FirstElmt(S))):
            return NilaiTertinggi(Tail(S))
        else:
            return max2(SumElmt(Nilai(FirstElmt(S))), NilaiTertinggi(Tail(S)))


def MVP(C, S):
    if IsOneElmt(S):
        return FirstElmt(S)
    else:
        if IsEmpty(Nilai(FirstElmt(S))) or C != Kelas(FirstElmt(S)):
            return MVP(C, Tail(S))
        else:
            if SumElmt(Nilai(FirstElmt(S))) > SumElmt(Nilai(MVP(C, Tail(S)))):
                return FirstElmt(S)
            else:
                return MVP(C, Tail(S))


def BanyakPemalas(S):
    if IsEmpty(S):
        return 0
    else:
        if Nilai(FirstElmt(S)) == []:
            return 1 + BanyakPemalas(Tail(S))
        else:
            return BanyakPemalas(Tail(S))


def BanyakMhsLulus(S):
    if IsEmpty(S):
        return 0
    else:
        if AvgElmt(Nilai(FirstElmt(S))) >= 70:
            return 1 + BanyakMhsLulus(Tail(S))
        else:
            return BanyakMhsLulus(Tail(S))
        
