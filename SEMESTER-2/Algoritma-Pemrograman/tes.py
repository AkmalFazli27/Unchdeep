from statsmodels.stats.weightstats import ztest
import random
import pandas as pd

# Simulasi 100x lemparan dadu, angka 6 lebih sering muncul 2x
simulasi = []
for i in range(100):
    lemparan = random.choice([1, 2, 3, 4, 5, 6, 6])
    d = {"lemparan": lemparan}
    simulasi.append(d)

# Convert data simulasi ke dalam data frame
df = pd.DataFrame(simulasi)
print(df)

# Menerapkan one-sample Z-test

# Langkah 1: Mendefinisikan Hipotesis Nol dan Hipotesis Alternatif
# H0:Simulasi mungkin berasal dari dadu yang adil
# H1:Simulasi kemungkinan tidak berasal dari dadu yang adil

# Langkah 2 dan 3: Menghitung Nilai Z-Test dan p-Value
z_test, p_value = ztest(df["lemparan"], value=3.5)

# Print the results
print("Z-Test:", z_test)
print("P-value:", p_value)

# Langkah 4: Tarik Kesimpulan
alpha = 0.05  # Significance level
if p_value < alpha:
    print("H0 Ditolak: Simulasi kemungkinan tidak berasal dari dadu yang adil.")
else:
    print("H0 Diterima: Simulasi mungkin berasal dari dadu yang adil.")



# ====================================

# Simulasi 50x lemparan dadu, angka 6 lebih sering muncul 2x
simulasi = []
for i in range(50):
    lemparan = random.choice([1, 2, 3, 4, 5, 6, 6])
    d = {"lemparan": lemparan}
    simulasi.append(d)

# Convert data simulasi ke dalam data frame
df = pd.DataFrame(simulasi)

print(df.head())

# Menerapkan one-sample Z-test

# Langkah 1: Mendefinisikan Hipotesis Nol dan Hipotesis Alternatif
# H0:Simulasi mungkin berasal dari dadu yang adil
# H1:Simulasi kemungkinan tidak berasal dari dadu yang adil

# Langkah 2 dan 3: Menghitung Nilai Z-Test dan p-Value
z_test, p_value = ztest(df["lemparan"], value=3.5)

# Print the results
print("Z-Test:", z_test)
print("P-value:", p_value)

# Langkah 4: Tarik Kesimpulan
alpha = 0.05  # Significance level
if p_value < alpha:
    print("H0 Ditolak: Simulasi kemungkinan tidak berasal dari dadu yang adil.")
else:
    print("H0 Diterima: Simulasi mungkin berasal dari dadu yang adil.")

# ==============================

# Simulasi 50x lemparan dadu, angka 6 lebih sering muncul 2x
simulasi = []
for i in range(10000):
    lemparan = random.choice([1, 2, 3, 4, 5, 6, 6])
    d = {"lemparan": lemparan}
    simulasi.append(d)

# Convert data simulasi ke dalam data frame
df = pd.DataFrame(simulasi)

print(df)

# Menerapkan one-sample Z-test

# Langkah 1: Mendefinisikan Hipotesis Nol dan Hipotesis Alternatif
# H0:Simulasi mungkin berasal dari dadu yang adil
# H1:Simulasi kemungkinan tidak berasal dari dadu yang adil

# Langkah 2 dan 3: Menghitung Nilai Z-Test dan p-Value
z_test, p_value = ztest(df["lemparan"], value=3.5)

# Print the results
print("Z-Test:", z_test)
print("P-value:", p_value)

# Langkah 4: Tarik Kesimpulan
alpha = 0.05  # Significance level
if p_value < alpha:
    print("H0 Ditolak: Simulasi kemungkinan tidak berasal dari dadu yang adil.")
else:
    print("H0 Diterima: Simulasi mungkin berasal dari dadu yang adil.")