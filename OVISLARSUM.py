    m=1000000007
     
    l, r, mod = raw_input().split()
    l = int(l)
    r = int(r)
    mod = int(mod)
    ans = 0
     
    if (l%mod) != 0:
    	x = mod - (l%mod)
    	if r-l+1 <= x:
    		print(int(( ( ((r%mod)*((r%mod)+1)) // 2) - ((((l%mod)-1)*(l%mod))//2) )%m))
    		exit()
    	else:
    		ans = ( ((mod*(mod-1))//2) - ( (((l%mod)-1)*(l%mod))//2) )%m
    		l += x;
    		
    ans = (ans +  (((r-l+1)//mod) * ((mod*(mod-1))//2) ) )%m
     
    l += mod*((r-l+1)//mod)
     
    if l>r:
    	print(int(ans))
    	exit()
     
    ans = (ans+ (((r%mod)*((r%mod) + 1))//2) )%m
    print(int(ans)) 