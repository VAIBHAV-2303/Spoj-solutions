    import math
     
    s = str(input())
    ind = s.find('(')
    i = ind + 1
    while s[i] != ',':
    	i += 1
    x = float(s[ind + 1:i])
    ind = i
    i = ind + 1
    while s[i] != ')':
    	i += 1
    y = float(s[ind+1:i])
    cur = 0.0
     
    while True:
    	try:
    		s = str(input())
    		ind = s.find('(')
    		i = ind + 1
    		while s[i] != ',':
    			i += 1
    		newx = float(s[ind + 1:i])
    		ind = i
    		i = ind + 1
    		while s[i] != ')':
    			i += 1
    		newy = float(s[ind+1:i])
    		cur += math.sqrt((x-newx)*(x-newx)+(y-newy)*(y-newy))
    		print("The salesman has traveled a total of %.3f kilometers." %cur)
    		x=newx
    		y=newy
    	except EOFError:
    		break 
