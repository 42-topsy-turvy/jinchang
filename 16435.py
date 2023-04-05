N,L = map(int,input().split())
n = list(map(int,input().split()))
n.sort()
for x in range(N):
    if n[x]<=L:
        L+=1
print(L)
