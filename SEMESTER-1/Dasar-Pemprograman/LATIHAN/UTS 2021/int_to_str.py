def IntToStr(d,m,y):
    return f"{d} {Month(m)} {y}"

def Month(m):
    if m == 1 : return "Januari"
    if m == 2 : return "Februari"
    if m == 3 : return "Maret"
    if m == 4 : return "April"
    if m == 5 : return "Mei"
    if m == 6 : return "Juni"
    if m == 7 : return "Juli"
    if m == 8 : return "Agustus"
    if m == 9 : return "September"
    if m == 10 : return "Oktober"
    if m == 11 : return "November"
    if m == 12 : return "Desember"

print(IntToStr(1,1,2021))