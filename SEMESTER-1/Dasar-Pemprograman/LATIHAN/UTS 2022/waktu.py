def MakeTime(hari,jam,menit,detik):
    return [hari,jam,menit,detik]

def Hari(time):
    return time[0]

def Jam(time):
    return time[1]

def Menit(time):
    return time[2]

def Detik(time):
    return time[3]

def HariKeInt(h):
    if h == "Senin" : return 1
    if h == "Selasa" : return 2
    if h == "Rabu" : return 3
    if h == "Kamis" : return 4
    if h == "Jumat" : return 5
    if h == "Sabtu" : return 6
    if h == "Minggu" : return 7

def GetSelisihWaktu(w1,w2):
    return abs(((HariKeInt(Hari(w1)) * 86400) + (Jam(w1) * 3600) + (Menit(w1) * 60) + Detik(w1)) - ((HariKeInt(Hari(w2)) * 86400) + (Jam(w2) * 3600) + (Menit(w2) * 60) + Detik(w2)))

print(
    GetSelisihWaktu(
        MakeTime("Senin",6,45,49),
        MakeTime("Selasa",8,30,59)
    )
)

print(
    GetSelisihWaktu(
        MakeTime("Rabu",10,12,47),
        MakeTime("Kamis",3,35,33)
    )
)
