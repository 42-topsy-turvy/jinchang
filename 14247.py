n = int(input())
wood = list(map(int,input().split()))
l = list(map(int,input().split()))
re = 0
arr = []
for x in range(n):
    arr.append([wood[x], l[x]])

arr.sort(key = lambda x:x[1])

for x in range(n):
    re += arr[x][0] + arr[x][1] * x
print(re)
