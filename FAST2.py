    T = int(input())
    m = 1298074214633706835075030044377087
     
    for _ in range(T):
    	n = int(input())
    	n += 1
    	ans = 1
    	x = 2
    	while n > 0:
    		if (n%2) == 1:
    			ans = (ans * x)%m
    		n >>= 1
    		x = (x * x)%m
     
    	print(ans-1) 