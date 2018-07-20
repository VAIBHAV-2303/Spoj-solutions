    T=int(input())
    for _ in range(T):
    	n, i = raw_input().split()
    	n = int(n)
    	i = int(i)
    	ans=0
    	for j in range(i):
    		ans += ((n-2)**j)*(n**(i-1-j))
    	
    	if i == 1:
    		print(n)
    	elif i == 2:
    		print(n*n)
    	else:
    		print(2*ans) 
