import sys
input = sys.stdin. readline

n, m = map(int, input().split())
t = [0] * (n + 1)
party = []
kp = list(map(int, input().split()))[1:]
for p in kp:
    t[p] = 1

for i in range(m):
    pp = list(map(int, input().split()))[1:]
    party.append(pp)

for _ in range(m):
    for i in range(m):
        f = True
        for p in party[i]:
            if t[p]: f = False
        if f: continue
        for p in party[i]:
            t[p] = 1

res = 0
for pp in party:
    f = True
    for p in pp:
        if t[p]: f = False
    if f: res += 1

print(res)