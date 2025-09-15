"""
DEFINISI DAN SPESIFIKASI
ubah_celcius : 1 real -> real, 1 string -> string
 {ubah_celcius (suhu, kode) menentukan suhu dalam celcius menjadi
reamur atau fahrenheit atau kelvin}
"""

# NO 1
def ubah_celcius (suhu : float, kode : str):
    def celcius_reamur (suhu : float) -> float:
        return suhu * (4/5)
    def celcius_fahrenheit (suhu : float) -> float:
        return (suhu * (9/5)) + 32
    def celcius_kelvin (suhu : float) -> float:
        return suhu + 273.15
    
    if kode == "R":
        return celcius_reamur (suhu)
    if kode == "F":
        return celcius_fahrenheit (suhu)
    if kode == "K":
        return celcius_kelvin (suhu)
    

print(ubah_celcius (-15.0,"R")) # -> -12
print(ubah_celcius (85.0,"F")) # -> 12
print(ubah_celcius (53.0,"K")) # -> 326
