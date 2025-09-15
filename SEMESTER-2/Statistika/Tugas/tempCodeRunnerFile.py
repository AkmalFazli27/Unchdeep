import pandas as pd

df = pd.read_csv('D:\Ameng\Kuliah\Statistika\Tugas\Latihan.csv')

print("Dataset: ")
print(df.to_string(index=False))

mean_tipe1 = df['Tipe1'].mean()
mean_tipe2 = df['Tipe2'].mean()
mean_tipe3 = df['Tipe3'].mean()
mean_tipe4 = df['Tipe4'].mean()

median_tipe1 = df['Tipe1'].median()
median_tipe2 = df['Tipe2'].median()
median_tipe3 = df['Tipe3'].median()
median_tipe4 = df['Tipe4'].median()

print("\n================\n")

print(f"Nilai rata-rata pada kolom Tipe1: {mean_tipe1}")
print(f"Nilai rata-rata pada kolom Tipe2: {mean_tipe2}")
print(f"Nilai rata-rata pada kolom Tipe3: {mean_tipe3}")
print(f"Nilai rata-rata pada kolom Tipe4: {mean_tipe4}")

print("\n================\n")

print(f"Nilai median pada kolom Tipe1: {median_tipe1}")
print(f"Nilai median pada kolom Tipe2: {median_tipe2}")
print(f"Nilai median pada kolom Tipe3: {median_tipe3}")
print(f"Nilai median pada kolom Tipe4: {median_tipe4}")

print("\n================\n")


