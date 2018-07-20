    def gcd(a, b):
    	if b == 0:
    		return a
    	return gcd(b, a%b)
     
    T = int(input())
    for _ in range(T):
    	n, a, b = raw_input().split()
    	n = long(n)
    	a = long(a)
    	b = long(b)
    	print(str(n)*gcd(a, b)) 
