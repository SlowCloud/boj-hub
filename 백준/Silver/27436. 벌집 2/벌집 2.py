n=int(input())
l=0
r=10000000000000000000
while l <= r:
    m = (l + r) // 2
    now = m * (m + 1) * 3 + 1
    if n <= now:
        r = m - 1
    else:
        l = m + 1
print(l + 1)