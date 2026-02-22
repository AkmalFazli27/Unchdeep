def deteksi_sinyal():
    sinyal = input().strip()
    gangguan = []
    dict_sinyal = {}
    
    for char in sinyal:
        if char in dict_sinyal:
            dict_sinyal[char] += 1
        else:
            dict_sinyal[char] = 1
            
    sinyal_dominan = max(dict_sinyal, key=dict_sinyal.get)
    
    for i in range(len(sinyal)):
        if sinyal[i] == sinyal_dominan:
            continue
        else:
            gangguan.append(i+1)
    
    if len(gangguan) == 0:
        print("-1")
    else:
        print(" ".join(map(str, gangguan)))
        

deteksi_sinyal()