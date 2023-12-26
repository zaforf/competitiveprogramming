N,K = map(int,input().split())

a = [*map(int,input().split())]
b = [*map(int,input().split())]


ai = {a[i]:i for i in range(len(a))}
bi = {b[i]:i for i in range(len(b))}
ansc = [0 for i in range(K)]
for i in range(len(b)):
	if b[i] in ai:
		ansc[(ai[b[i]]-bi[b[i]]+K)%K]+=1
f = max(ansc)

b = b[::-1]
bi = {b[i]:i for i in range(len(b))}
ansc = [0 for i in range(K)]
for i in range(len(b)):
	if b[i] in ai:
		ansc[(ai[b[i]]-bi[b[i]]+K)%K]+=1
t = max(ansc)

ans = 0
for i in range(1,N+1):
	if not i in ai and not i in bi:
		ans+=1


print(max(f,t)+ans)