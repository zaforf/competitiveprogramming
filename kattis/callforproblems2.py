n,k = map(int,input().split())

d = [int(input()) for _ in range(n)]

print(min(len(set(d)),k))