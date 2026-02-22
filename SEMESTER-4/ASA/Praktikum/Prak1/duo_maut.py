def duo_maut():
    n = int(input().strip())
    kekuatan = list(map(int, input().strip().split()))
    
    kekuatan.sort()
    
    max_kekuatan = kekuatan[-1] + kekuatan[-2]
    
    print(max_kekuatan)
    
duo_maut()