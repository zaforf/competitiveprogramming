read = open("advent3.in", "r").readline
alpha = [chr(i) for i in range(97,97+26)]
alpha += [chr(i).upper() for i in range(97,97+26)]
print(alpha)
ans = 0
# inp = read()
# while inp!="end":
#     infirst = set(inp[:len(inp)//2])
#     used = set()
#     for i in range(len(inp)//2,len(inp)):
#         if inp[i] in infirst and inp[i] not in used:
#             used.add(inp[i])
#             ans+=alpha.index(inp[i])+1
#     inp = read()
# print(ans)
# part 1

inp = read().strip()
while inp!="end":
    cnt = [0 for i in range(52)]
    for i in set(inp):
        cnt[alpha.index(i)]+=1
    for j in range(2):
        for i in set(read().strip()):
            cnt[alpha.index(i)]+=1
    ans += cnt.index(3)+1
    inp = read().strip()
print(ans)