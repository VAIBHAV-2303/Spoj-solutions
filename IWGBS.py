    dp=[-1 for _ in range(10001)]
    dp[0]=1
    dp[1]=2
    dp[2]=3
    def fn(n):  
        if dp[n]==-1:
            dp[n]=fn(n-1)+fn(n-2)
        return dp[n]
     
    dp[1000]=fn(1000)
    dp[1500]=fn(1500)
    dp[2000]=fn(2000)
    dp[2500]=fn(2500)
    dp[3000]=fn(3000)
    dp[3500]=fn(3500)
    dp[4000]=fn(4000)
    dp[4500]=fn(4500)
    dp[5000]=fn(5000)
    dp[5500]=fn(5500)
    dp[6000]=fn(6000)
    dp[6500]=fn(6500)
    dp[7000]=fn(7000)
    dp[7500]=fn(7500)
    dp[8000]=fn(8000)
    dp[8500]=fn(8500)
    dp[9000]=fn(9000)
    dp[9500]=fn(9500)
    n=int(input())
    print(fn(n)) 
