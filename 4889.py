cnt=0
result=0
ls=list(input())
i=1
while '-' not in ls:
    for x in range(len(ls)):
        if ls[x]=='{':
            cnt=cnt+1
        elif ls[x]=='}':
            cnt=cnt-1
        if cnt<0:
            ls[x]='{'
            cnt=cnt+2
            result=result+1
    result=result+cnt//2
    print(str(i)+".",result)
    i=i+1
    ls=list(input())
    cnt=0
    result=0
