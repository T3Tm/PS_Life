from decimal import*
D=Decimal
getcontext().prec=1000
for _ in[0]*int(input()):
    output = f'{D(input())**(D(1)/D(3)):.500f}'
    print(output[:output.index('.')+11])