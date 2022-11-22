read = open("art.in", "r").readline
write = open("art.out", "w").write

N = int(read())
art = [read() for i in range(N)]
vis = set()
coords = {}

for i in range(N):
    for j in range(N):
        if art[i][j] not in vis and art[i][j]!="0":
            vis.add(art[i][j])
            coords[art[i][j]] = [N,0,N,0]
        if art[i][j] != "0":
            coords[art[i][j]] = [min(coords[art[i][j]][0],i),max(coords[art[i][j]][1],i),min(coords[art[i][j]][2],j),max(coords[art[i][j]][3],j)]
for key in coords:
    for i in range(coords[key][0],coords[key][1]+1):
        for j in range(coords[key][2],coords[key][3]+1):
            if art[i][j] != key and art[i][j] in vis:
                vis.remove(art[i][j])
write(str(len(vis)))
