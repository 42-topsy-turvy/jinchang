N=int(input())
arr = list(map(int, input().split()))
re = 0
mlist = []
if N==1:
    print(sum(arr)-max(arr))
else:
    mlist.append(min(arr[0], arr[5]))
    mlist.append(min(arr[1], arr[4]))
    mlist.append(min(arr[2], arr[3]))
    mlist.sort()
    m1 = mlist[0]
    m2 = mlist[0] + mlist[1]
    m3 = sum(mlist)
    three = 4
    two = 4 * (N - 1) + 4 * (N - 2)
    one = 4 * (N - 2) * (N - 1) + (N - 2) ** 2
    re += m1 * one
    re += m2 * two
    re += m3 * three
    print(re)
