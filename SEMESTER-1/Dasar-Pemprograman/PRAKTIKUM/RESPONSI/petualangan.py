def Opertor(S):
    return S[0]

def Operand1(S):
    return S[1]

def Operand2(S):
    return S[2]

def EvaluateExpression(S):
    if Opertor(S) == '+':
        return Operand1(S) + Operand2(S)
    if Opertor(S) == '-':
        return Operand1(S) - Operand2(S)
    if Opertor(S) == '*':
        return Operand1(S) * Operand2(S)
    if Opertor(S) == '/':
        return Operand1(S) / Operand2(S)
    
print(EvaluateExpression(['+',5,5]))