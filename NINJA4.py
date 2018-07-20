    T = int(input())
    for _ in range(T):
    	n = int(input())
    	if n%4 == 0:
    		print (-2)*(n/4), (-2)*(n/4)
    	elif n%4 == 1:
    		print (-2)*(n/4) + n, (-2)*(n/4)
    	elif n%4 == 2:
    		print (-2)*(n/4) + n-1, (-2)*(n/4) + n
    	else:
    		print (-2)*(n/4) - 2, (-2)*(n/4) + n-1 
