    a=[]
    n=int(input())
    for _ in range(n):
    	pui=int(input())
    	if pui%2==0:
    		temp=str(bin(pui))
    		temp=temp[2:]
    		temp=temp[::-1]
    		a.append(int(temp, 2))
    	else:
    		a.append(pui)
    for i in range(n):		
    	print(a[i]) 
