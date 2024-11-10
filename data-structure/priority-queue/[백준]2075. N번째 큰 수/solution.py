import sys
import heapq
input = sys.stdin.readline

n = int(input())
h = []
for _ in range(n):
    li = map(int, input().split())
    for x in li:
        if len(h) < n:
            heapq.heappush(h, x)
        elif h[0] < x: # else 도 무방함
            heapq.heappushpop(h, x)
print(h[0])