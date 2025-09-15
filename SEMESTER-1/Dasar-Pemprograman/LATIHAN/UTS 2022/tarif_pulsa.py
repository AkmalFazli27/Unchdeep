def TarifPulsa(kode,detik):
    if kode == "A":
        if detik <= 30:
            return 200
        else:
            return 200 + ((detik - 30) * 10)
    if kode == "B":
        if detik <= 30:
            return 300
        else:
            return 300 + ((detik - 30) * 20)
    if kode == "C":
        if detik <= 30:
            return 350
        else:
            return 350 + ((detik - 30) * 25)

print(TarifPulsa("A",40))
print(TarifPulsa("B",29))
print(TarifPulsa("C",34))