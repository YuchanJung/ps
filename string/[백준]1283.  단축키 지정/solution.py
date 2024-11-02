import sys
input = sys.stdin.readline

n = int(input())
menu = [input().strip() for _ in range(n)]
key = []

for i in range(n):
    f = True
    wl = menu[i].split()
    for j in range(len(wl)):
        k = wl[j][0]
        if k.lower() in key: continue
        key.append(k.lower())
        wl[j] = wl[j].replace(k, f'[{k}]', 1)
        menu[i] =  ' '.join(wl)
        f = False
        break

    if f:
        for c in menu[i]:
            if c == ' ' or c.lower() in key: continue
            key.append(c.lower())
            menu[i] = menu[i].replace(c, f'[{c}]', 1)
            break
             
    print(menu[i])