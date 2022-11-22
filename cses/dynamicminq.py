N,q = map(int,input().split())
st = [0 for i in range(N)]

def build():
    for i in range(N-1,0,-1):
        st[i] = min(st[2*i],st[2*i+1])
def upd(i,k):
    i+=N
    st[i]=k
    while(i>1):
        st[i//2] = min(st[i],st[i^1])
        i//=2
def query(l,r):
    l+=N
    r+=N
    res=int(1e9+1)
    while (l<=r):
        if (l%2==1):
            res=min(res,st[l])
            l+=1
        if (r%2==0):
            res=min(res,st[r])
            r-=1
        l//=2
        r//=2
    return res

st.extend(map(int,input().split()))
build()
for i in range(q):
    a,b,c = map(int,input().split())
    if a==1:
        upd(b-1,c)
    else:
        print(query(b-1,c-1))