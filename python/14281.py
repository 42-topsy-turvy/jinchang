import math
N = int(input())
a = list(map(int,input().split()))
cnt=0
if len(a) == 1 or len(a) == 2:
    print(0)
else:
    flag = 1
    while(flag):
        flag = 0
        for x in range(1,N-1):
            if a[x-1] + a[x+1] < 2 * a[x]:
                cnt += a[x] - math.floor((a[x-1] + a[x+1])/2)
                a[x] = math.floor((a[x-1] + a[x+1])/2)
                flag = 1
    print(cnt)
