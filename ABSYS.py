    T=int(input())
    for _ in range(T):
    	pui=raw_input()
    	a, b, c, d, e = raw_input().split()
     
    	if "m" in a:
    		c=int(c)
    		e=int(e)
    		a=e-c
    		print(str(a)+' + '+str(c)+" = "+ str(e))
    	elif "m" in c:
    		a=int(a)
    		e=int(e)
    		c=e-a
    		print(str(a)+' + '+str(c)+" = "+ str(e))
    	elif "m" in e:
    		a=int(a)
    		c=int(c)
    		e=a+c
    		print(str(a)+' + '+str(c)+" = "+ str(e))
    	else:
    		print(str(a)+' + '+str(c)+" = "+ str(e)) 

