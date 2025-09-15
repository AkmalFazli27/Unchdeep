def PecahanCampuranToDesimal(bil,n,d):
    if bil < 0 : return (d * bil - n) / d
    return (d * bil + n) / d

print(PecahanCampuranToDesimal(-2,1,2))
print(PecahanCampuranToDesimal(2,1,2))
