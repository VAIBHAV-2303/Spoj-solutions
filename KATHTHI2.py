    T = int(input())
    for _ in range(T):
    	k, p = raw_input().split()
    	k = int(k)
    	p = float(p)	
     
    	if p == 1.00:
    		print(k)
    		continue
     
    	if (k/p) == k // p:
    		print(int((k//p) - 1))
    	else:
    		print(int(k//p)) 