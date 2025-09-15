from bahan_list import *

T = makePN(
    "A",
    [
        makePN("K", [makePN("M",[]),makePN("L",[]),makePN("F",[])]),
        makePN("Z", [makePN("I",[]),makePN("R",[]),makePN("Y",[makePN("D",[])])])
    ],
)
print(T)

def SubTreeElemt(x, PN):
    if IsTreeNEmpty(PN):
        return []
    elif Akar(PN) == x and Anak(PN) == []:
        return [Akar(PN), []]
    elif Akar(PN) == x:
        return Konso(Akar(PN), Anak(PN))
    elif IsTreeNEmpty(Anak(PN)):
        return []
    else:
        return SubTreeElemt(x, FirstElmt(Anak(PN))) or SubTreeElemtChild(x, Tail(Anak(PN)))

def SubTreeElemtChild(x, PN):
    if IsTreeNEmpty(PN):
        return []
    else:
        return SubTreeElemt(x, FirstElmt(PN)) or SubTreeElemtChild(x, Tail(PN))


print(SubTreeElemt("L",T))
