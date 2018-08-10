    def mul(x00, x01, x10, x11, y00, y01, y10, y11, m):    	
        c00 = (((x00*y00) % m) + ((x01*y10) % m)) % m
        c01 = (((x00*y01) % m) + ((x01*y11) % m)) % m
        c10 = (((x10*y00) % m) + ((x11*y10) % m)) % m
        c11 = (((x10*y01) % m) + ((x11*y11) % m)) % m
        return c00, c01, c10, c11
         
    T = int(input())
    for _ in range(T):
        n, k, m = input().split()
        n = int(n)
        k = int(k)
        m = int(m)
        if n == 1:
            print(k%m)
            continue
        if n == 2:
            print(( ((k*k)%m) - k)%m)
            continue
        ans00 = 1 
        ans01 = 0
        ans10 = 0
        ans11 = 1
        a00 = (k-1)%m
        a01 = (k-1)%m
        a10 = 1
        a11 = 0
        n -= 2
     
        while n >= 1:
            if n%2 == 1:
                ans00, ans01, ans10, ans11 = mul(ans00, ans01, ans10, ans11, a00, a01, a10, a11, m)
            n>>=1
            a00, a01, a10, a11 = mul(a00, a01, a10, a11, a00, a01, a10, a11, m)
        ans00 = ( ((k*ans00)%m) + ans01)%m
        print(( ans00 * ((k-1)%m) )%m)
          
