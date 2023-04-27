N = int(input())
T = 0
F = 0
for x in range(1,N + 1):
    t = x
    f = x
    while t%2 == 0:
        T+=1
        t/=2
    while f%5 == 0:
        F+=1
        f/=5
print(min(T,F))
