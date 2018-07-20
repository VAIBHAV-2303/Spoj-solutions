    from decimal import *
     
    getcontext().prec=1000
    T=int(input())
    for _ in range(T):
    	n=int(input())
    	mys=str(Decimal(1/(2**(n-1))))
    	i=len(mys)
    	i-=1
    	while mys[i]!='E' and i>=0:
    		i-=1
     
    	if i==-1:
    		print(mys)
    	else:
    		pui=int(mys[i+2:])
    		print('0'+'.'+'0'*(pui-1)+mys[0:i].replace('.', ''))
     
