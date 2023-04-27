N,M=map(int,input().split())
m = []
re = [[0]*M for _ in range(N-1)]
for x in range(N-1):
    m.append(list(map(str,input().split())))
for x in range(N-1):
    for y in range(int(m[x][0])):
        if m[x][2 * y + 2] == 'R':
            for z in range(0,int(m[x][2*y+1])-1):
                re[x][z] = 0
            for z in range(int(m[x][2 * y + 1])-1,M):
                re[x][z] = 1
        elif m[x][2 * y + 2] == 'L':
            if 1 in m[x][0:M]:
                for z in range(int(m[x][2 * y + 1]),M):
                    re[x][z] = 0
                for z in range(int(m[x][2*y+1])-1, -1,-1):
                    if 1 in re[x][0:z]:
                        re[x][z] = 1
            elif 1 not in m[x][0:M]:
                for z in range(int(m[x][2 * y + 1]),M):
                    re[x][z] = 0
                for z in range(0,int(m[x][2*y+1])):
                    re[x][z] = 1
print(*re)
