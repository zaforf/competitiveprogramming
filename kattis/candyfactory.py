n,k = map(int, input().split())

a = [int(input()) for _ in range(n)]

cols = max(max(a), (sum(a) + k - 1) // k)
print(cols*k - sum(a))