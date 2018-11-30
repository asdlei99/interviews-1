import math

n = int(input())
k = int(input())

if k > (n - n//2) * (n // 2):
    print('-')
else:
    a = math.ceil((4 * k) ** 0.5)
    x = (int)(a - (a * a - 4 * k) ** 0.5) // 2
    print(x)
    res = "B" * (n - a) + "A" * x + "B" * (a - x)
    print(res)
