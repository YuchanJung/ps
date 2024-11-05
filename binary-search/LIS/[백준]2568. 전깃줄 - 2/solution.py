from bisect import bisect_left # lower bound
import sys
input = sys.stdin.readline

n = int(input())
arr = []
lis = [1e9] * n
idx = [0] * n
for i in range(n):
    a, b = map(int, input().split())
    arr.append([a, b])
arr.sort()
for i in range(n):
    x = bisect_left(lis, arr[i][1])
    lis[x] = arr[i][1]
    idx[i] = x

l = bisect_left(lis, 1e9)
ans1 = n - l
print(ans1)
ans2 = [0] * n
j = l - 1
for i in range(n - 1, -1, -1):
    if idx[i] == j:
        ans2[i] = 1
        j -= 1
for i in range(n):
    if not ans2[i]:
        print(arr[i][0])