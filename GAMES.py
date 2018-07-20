    def fn(n):
    	n=float(str('0.'+str(n)[str(n).find('.')+1:]))
    	if len(str(n))==6 and str(n)[5] != '0':
    		i=2
    		x=n
    		while len(str(n)) == 6:
    			n+=x
    			i+=1
    		i-=1
    		return i*fn(n) 
    	if len(str(n))==5 and str(n)[4] != '0':
    		i=2
    		x=n
    		while len(str(n)) == 5:
    			n+=x
    			i+=1
    		i-=1
    		return i*fn(n) 
    	if len(str(n))==4 and str(n)[3] != '0':
    		i=2
    		x=n
    		while len(str(n)) == 4:
    			n+=x
    			i+=1
    		i-=1
    		return i*fn(n) 
    	if len(str(n))==3 and str(n)[2] != '0':
    		i=2
    		x=n
    		while str(n)[2] != '0':
    			n+=x
    			i+=1
    		i-=1
    		return i*fn(n) 
     
    	return 1
     
    T=int(input())
    for _ in range(T):
    	n=raw_input()
    	n=float(n)
    	print(fn(n))
     
