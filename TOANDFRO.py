    while True:
    	n=int(input())
    	if n==0:
    		break
     
    	msg=str(input())
    	arr=[]
    	i=0
    	count=0
    	while i<len(msg):
    		count+=1
    		if count%2==1:
    			arr.append(msg[i:i+n])
    			i+=n
    		else:
    			pui=msg[i:i+n]
    			arr.append(pui[::-1])
    			i+=n
     
    	ans=''
    	count=0
    	# print(len(arr))
    	# print(arr)
    	for i in range(n):	
    		for j in range(len(arr)):
    			ans+=arr[j][i]
     
    	print(ans) 
