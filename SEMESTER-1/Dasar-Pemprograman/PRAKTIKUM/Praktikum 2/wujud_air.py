# NO 2
def wujud_air (suhu : int):
    if suhu <= 0:
        return "Wujud : Es (padat)"
    elif suhu > 0 and suhu < 100:
        return "Wujud : Cair"
    elif suhu >= 100:
        return "Wujud : Uap"
    
print(wujud_air (-7)) # -> Es
print(wujud_air (99)) # -> Cair
print(wujud_air (100)) # -> Uap