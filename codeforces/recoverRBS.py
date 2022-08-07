N = int(input())

for i in range(N):
    string = input()
    n = len(string)
    x = n//2 - string.count('(')
    cnt = [0 for i in range(n)]
    curr = 0
    ind = -1
    if x == 0 or string.count("?")==x:
        print("YES")
        continue
    for i in range(n):
        if string[i] == "(": curr+=1
        elif string[i] == ")": curr -= 1
        else:
            if x<=0: 
                curr -= 1
                if ind == -1:
                    ind = i
                continue
            curr += 1
            x-=1
        cnt[i] = curr
    for i in reversed(range(ind)):
        if i == ind-1: continue
        cnt[i] = min(cnt[i],cnt[i+1])
    x = n//2 - string.count('(')
    ok = False
    for i in range(n):
        if x==0: break
        if string[i] != "?": continue
        x-=1 
        if cnt[i]>1:
            print("NO")
            ok = True
            break
    if not ok:
        print("YES")
    
                
    
        
