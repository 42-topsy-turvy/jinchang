T = int(input())
for x in range(T):
    N = int(input())
    zero = [0]*(N+1)
    one = [0]*(N+1)
    if N == 0:
        zero[0] = 1
    else:
        zero[0] = 1
        one[1] = 1;
    for y in range(2,N+1):
        zero[y] = zero[y - 1] + zero[y - 2]
        one[y] = one[y - 1] + one[y - 2]
    print(zero[N], one[N])
