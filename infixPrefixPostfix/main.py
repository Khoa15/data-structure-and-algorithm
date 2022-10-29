def getPriority(op):
    if op == "+" or op == "-":
        return 1
    if op == '*' or op == '/':
        return 2
    if op == '^':
        return 3
    return 0

def infixToPostfix(infix):
    postfix = ""
    stk = []
    for x in infix:
        if x == ' ':
            continue
        if x == '(':
            stk.append(x)
        elif x == ')':
            while stk[-1] != '(':
                postfix += stk[-1]
                stk.pop()
                if len(stk) == 0:
                    break
            if len(stk) != 0: 
                stk.pop()
        elif x == '+' or x == '-' or x == '*' or x == '/' or x == '^':
            while len(stk) != 0 and getPriority(x) <= getPriority(stk[-1]):
                postfix += stk[-1]
                stk.pop()
            stk.append(x)
        else:
            postfix += x
        
    while len(stk) != 0:
        postfix += stk[-1]
        stk.pop()
    return postfix

print(infixToPostfix("9-1*3+(4 ^ 5*3)"))