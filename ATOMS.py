    T=int(input())
    for _ in range(T):
    	n, k, m = raw_input().split()
    	n=long(n)
    	k=long(k)
    	m=long(m)
    	t=0
    	while n<=m:
    		n=n*k
    		t+=1
    	if t<1:
    		print(0)
    	else:
    		print(t-1) 
