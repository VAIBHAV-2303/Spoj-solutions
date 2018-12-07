    from math import gcd
     
    for _ in range(int(input())):
    	m, n = input().split()
    	m = int(m)
    	n = int(n)
     
    	
    	pui = gcd(m, n)
    	while gcd(pui, m//pui) != 1:
    		pui = pui//(gcd(pui, m//pui))
    	lc = m//pui
     
    	pui = gcd(m, n)
    	while gcd(pui, n//gcd(m, n)) != 1:
    		pui = pui//(gcd(pui, n//pui))
    	lc *= n//pui
     
    	print(lc) 