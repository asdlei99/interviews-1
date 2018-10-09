import sys 

for line in sys.stdin:
    k, b, n, t = [int(i) for i in line.split()]

    s = 1
    for i in range(n):
        s = s * k + b
    now = t
    for i in range(1, n + 1):
        now = now * k + b
        if now >= s:
            print(i)
            break
