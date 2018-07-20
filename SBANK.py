    T=int(input())
    for _ in range(T):
    	n=int(input())
    	pui=[]
    	for i in range(n):
    		pui.append(str(raw_input()))
     
    	c=raw_input()
     
    	for i in range(n):
    		pui[i]=long(pui[i].replace(" ", ""))
     
    	pui.sort()
    	i=0
    	while i < n:
    		count=1
    		while i+1<n and pui[i]==pui[i+1]:
    			count+=1
    			i+=1
     
    		pui[i]=str(pui[i])
    		while len(pui[i])<26:
    			pui[i]='0'+pui[i]
    		print pui[i][0:2], pui[i][2:10], pui[i][10:14], pui[i][14:18], pui[i][18:22], pui[i][22:26], count
    		i+=1
    	print
    	del pui[:] 
