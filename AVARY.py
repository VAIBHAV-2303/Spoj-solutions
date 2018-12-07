    ans = [[], [0, 1, 5, 6]]
     
    for i in range(2, 501):
    	ans.append([])
    	# print(i, len(ans[i-1]))
    	for j in range(len(ans[i-1])):
    		for k in range(10):
    			pui = k*(10**(i-1)) + ans[i-1][j]
    			if (pui*pui)%(10**i) == pui:
    				ans[i].append(pui)
    	ans[i].sort()	
     
    for t in range(int(input())):
    	n = int(input())
    	print('Case #' + str(t+1) + ': ', end = '')
    	flag = 0
    	for i in range(len(ans[n])):
    		if len(str(ans[n][i])) == n:
    			flag = 1
    			print(ans[n][i], end = ' ')
     
    	if flag == 0:
    		print('Impossible')
    	else:
    		print() 