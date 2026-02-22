def beda_ketinggian():
    n = map(int, input().strip().split())
    ketinggian = list(map(int, input().strip().split()))
    
    no_datar = [ketinggian[0]]
    for tinggi in ketinggian:
        if tinggi != no_datar[-1]:
            no_datar.append(tinggi)
    
    titik_ekstrem = [no_datar[0]]
    
    for i in range(1, len(no_datar) - 1):
        if no_datar[i - 1] < no_datar[i] > no_datar[i + 1]:
            titik_ekstrem.append(no_datar[i])
        elif no_datar[i - 1] > no_datar[i] < no_datar[i + 1]: 
            titik_ekstrem.append(no_datar[i])
    
    titik_ekstrem.append(no_datar[-1])
    beda_max = 0
    
    for i in range(len(titik_ekstrem) - 1):
        beda = abs(titik_ekstrem[i] - titik_ekstrem[i + 1])
        if beda_max < beda:
            beda_max = beda
    
    print(beda_max)
    
beda_ketinggian()