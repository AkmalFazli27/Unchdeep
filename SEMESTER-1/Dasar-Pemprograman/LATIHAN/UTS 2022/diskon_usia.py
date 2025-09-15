def MakeDate(d,m,y):
    return [d,m,y]

def Day(date):
    return date[0]

def Month(date):
    return date[1]

def Year(date):
    return date[2]

def MakeDiskon(kategori,diskon):
    return [kategori,diskon]

def Usia(TglLahir,TglBrkt):
    if Month(TglLahir) >= Month(TglBrkt) and Day(TglLahir) > Day(TglBrkt):
        return Year(TglBrkt) - Year(TglLahir) - 1
    return Year(TglBrkt) - Year(TglLahir)

def DiskonUsia(TglLahir,TglBrkt):
    if Usia(TglLahir,TglBrkt) <= 2 : return MakeDiskon("infant",75)
    if 2 < Usia(TglLahir,TglBrkt) <= 12 : return MakeDiskon("child",25)
    if Usia(TglLahir,TglBrkt) > 12 : return MakeDiskon("adult",0)

print(
    DiskonUsia(
        MakeDate(10,2,2000),
        MakeDate(2,2,2003)
    )
)

print(
    DiskonUsia(
        MakeDate(10,1,2000),
        MakeDate(1,1,2004)
    )
)

print(
    DiskonUsia(
        MakeDate(10,1,2000),
        MakeDate(1,1,2024)
    )
)