    T=int(input())
    for _ in range(T):
    	n, m = raw_input().split()
    	n=long(n)
    	m=long(m)
    	if n%2==0 and m%2==0:
    		print(m*(n/2))
    	else:
    		print(max((m*((n+1)/2)), (n*((m+1)/2))))
     
