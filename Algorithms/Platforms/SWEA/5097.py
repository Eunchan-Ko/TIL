import sys
sys.stdin = open("5097.txt")
for tc in range(int(input())):
    n, m = map(int,input().split())
    arr = list(map(int, input().split()))
    first = m % n
    print(f"#{tc+1}",arr[first])