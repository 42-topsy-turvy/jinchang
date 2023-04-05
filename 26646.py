N=int(input())
n = list(map(int,input().split()))
dp = [[100]*N for _ in range(N)]
for x in range(N):
    for y in range(x+1,N):
        dp[x][y] = min(dp[x][y-1] + dp[y-1][y],abs(n[x]-n[y])**2 + abs(n[x]+n[y])**2)
        print(dp[x][y])        
