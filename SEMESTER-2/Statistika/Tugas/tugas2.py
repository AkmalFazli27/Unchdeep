import pandas as pd

df = pd.read_csv('D:\Ameng\Kuliah\Statistika\Tugas\Latihan.csv')

print("Dataset: ")
print(df.to_string(index=False))

std_tipe1 = df['Tipe1'].std()
std_tipe2 = df['Tipe2'].std()
std_tipe3 = df['Tipe3'].std()
std_tipe4 = df['Tipe4'].std()

var_tipe1 = df['Tipe1'].var()
var_tipe2 = df['Tipe2'].var()
var_tipe3 = df['Tipe3'].var()
var_tipe4 = df['Tipe4'].var()

print("\n================\n")

print(f"Nilai standar deviasi pada kolom Tipe1: {std_tipe1}")
print(f"Nilai standar deviasi pada kolom Tipe2: {std_tipe2}")
print(f"Nilai standar deviasi pada kolom Tipe3: {std_tipe3}")
print(f"Nilai standar deviasi pada kolom Tipe4: {std_tipe4}")

print("\n================\n")

print(f"Nilai varians pada kolom Tipe1: {var_tipe1}")
print(f"Nilai varians pada kolom Tipe2: {var_tipe2}")
print(f"Nilai varians pada kolom Tipe3: {var_tipe3}")
print(f"Nilai varians pada kolom Tipe4: {var_tipe4}")

print("\n================\n")


