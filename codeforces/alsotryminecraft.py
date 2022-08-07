n,m = map(int,input().split())
mape = list(map(int,input().split()))

fwd = [0 for i in range(n)]
for i in range(n):
    if i==0:
        continue
    fwd[i] = fwd[i-1] + abs(min(0,mape[i]-mape[i-1]))
mape = mape[::-1]
bkwd = [0 for i in range(n)]
for i in range(n):
    if i==0:
        continue
    bkwd[i] = bkwd[i-1] + abs(min(0,mape[i]-mape[i-1]))
bkwd = bkwd[::-1]
for i in range(m):
    a,b = map(int,input().split())
    if a<=b:
        print(fwd[b-1]-fwd[a-1])
    else:
        print(bkwd[b-1]-bkwd[a-1])