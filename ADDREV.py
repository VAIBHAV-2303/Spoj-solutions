    T=int(input())
    for i in range(T):
    	a, b=raw_input().split()
    	a=str(a)
    	b=str(b)
    	a=a[::-1]
    	b=b[::-1]
    	ans=str(long(a)+long(b))
    	ans=ans[::-1]
    	print(long(ans))
     
