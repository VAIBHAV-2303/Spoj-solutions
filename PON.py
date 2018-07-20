    import random
     
    def power(x, y, m):
    	res = long(1)
    	while y > 0:
    		if y & 1 :
    			res = (res * x) % m
    		y = y / 2
    		x = (x * x) % m
    	return res
     
    def isprime(n, k):
    	if n == 4:
    		return False
    	if n == 2 or n == 3:
    		return True
     
    	while k > 0:
    		k -= 1
    		a = random.randint(2, n-1)
    		if power(a, n-1, n) != 1:
    			return False
    	return True
     
    T = int(input())
     
    for _ in range(T):
    	n = long(input())
    	if isprime(n, 5) == True:
    		print 'YES'
    	else:
    		print 'NO' 
