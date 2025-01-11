import sys
input = sys.stdin.readline

k, l = map(int, input().split())
info = {}
rank = 1
for i in range(l):
    student_id = input().strip()
    info[student_id] = rank
    rank += 1

li = sorted(info.items(), key=lambda x:x[1])

for i in range(k):
    if i >= len(li): break
    print(li[i][0])