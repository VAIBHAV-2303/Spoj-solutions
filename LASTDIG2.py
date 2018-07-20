    T=int(input())
    for _ in range(T):
        period=1;
        a, b = raw_input().split()
        a=long(a)
        b=long(b)
        if b==0:
            print(1)
            continue
        a = a%10;
        x = a;
        x=a*a;
        while (x%10)!=a:
            x=x*a
            period+=1
        x=1
        b-=1
        b=b%period
        x=a
        for i in range(b):
            x=x*a
     
        print(x%10)  
