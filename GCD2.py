    def gdd(a, b):
    	if b==0:
    		return a
    	else:
    		return gdd(b, a%b)
     
    T=int(input())
    for _ in range(T):
    	a, b = raw_input().split()
    	a=long(a)
    	b=long(b)
    	print(gdd(a, b)) 
