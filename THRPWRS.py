    def power(x, y):
    	res=long(1)
    	while y > 0:
    		if y & 1:
    			res = res * x
    		x = x * x
    		y = y / 2
    	return res
     
    while True:
    	n = long(raw_input())
    	if n == 0:
    		break
    	n -= 1
    	s=str()
    	s += '{ '
    	x=0
    	while n != 0:
    		if n&1:
    			s += str(power(3, x))
    			n /= 2
    			x += 1
    			if n == 0:
    				s += ' '
    			else:
    				s += ', '
    		else:
    			x += 1
    			n /= 2 
    	s += '}'
    	print(s)	 
