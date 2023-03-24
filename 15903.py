N,M =map(int,input().split())
a=list(map(int,input().split()))
for x in range(M):
    a.sort()
    tmp = a[0]+a[1]
    a[0] = tmp
    a[1] = tmp
print(sum(a))
