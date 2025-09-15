x = lambda a,t : 1/2 * a * t
print(int(x(4,3)))

# TERNARY OPERATION
# TITIK BEKU
wujud_air = lambda suhu : "Wujud : Es (padat)" if suhu <= 0 else ("Wujud : Cair" if suhu > 0 and suhu < 100 else "Wujud : Gas (uap)")
print(wujud_air (-7)) # -> Es
print(wujud_air (99)) # -> Cair
print(wujud_air (100)) # -> Uap
