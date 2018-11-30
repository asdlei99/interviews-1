import sys 

for line in sys.stdin:
    l, r = line.split()

    llen = len(l)
    rlen = len(r)

    mid = 0
    left = 0
    right = 0
    for i in range(llen + 1, rlen):
        mid += 9 * 10 ** (i - 2)

    # print(res)
    left += (9 - int(l[0])) * (9 ** max(llen - 2, 0))
    # print(res)
    if l[0] >= l[-1]:
        temp = 1
        for i in range(1, llen - 1):
            temp *= 9 - int(l[i]) + 1
        left += temp
    else:
        if llen >= 3:
            left += int('9' * (llen - 2)) - int(l[1:-1])
        # print(res)

    right += (int(r[0]) - 1) * (9 ** max(rlen - 2, 0))
    # print(res)
    if r[0] <= r[-1]:
        temp = 1
        for i in range(1, rlen - 1):
            temp *= int(r[i]) + 1
        right += temp
        # print(res)
    else:
        if rlen >= 3:
            right += int(r[1:-1])

    if llen == rlen:
        

    print(res)