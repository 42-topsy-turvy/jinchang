A,B=map(int,input().split())
cnt = 0
while (A!=B):
    if B%2==0 and A <= B//2:
        B//=2
    elif B%10==1 and A <= B//10:
        B//=10
    else:
        print(-1)
        break
    cnt += 1
if A == B:
    print(cnt + 1)
