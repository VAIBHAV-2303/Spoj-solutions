    dp = []
    factorial = []
    factorial.append(1)
    for i in range(1, 70):
    	factorial.append(factorial[i-1]*i)
     
    for i in range(1, 70):
    	dp.append(factorial[i]//(factorial[i//2]*factorial[i - (i//2)]))
     
    T = int(input())
     
    for _ in range(T):
    	n = int(input())
    	for i in range(0, 10000):
    		if dp[i] >= n:
    			print(i+1)
    			break 