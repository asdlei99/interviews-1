from functools import reduce

def factors(n):    
    return set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

[n, m] = [int(i) for i in input().split(' ')]

# print(factors(m))
fa = list(factors(m))
fa.sort()

# print(fa)

dp = [[1] * len(fa) for i in range(n)]

for i in range(1, n):
    for j in range(len(fa)):
        dp[i][j] = 0
        for x in range(0, j + 1):
            dp[i][j] += dp[i - 1][x]
            dp[i][j] %= 1e9 + 7

print(int(dp[n - 1][len(fa) - 1]))
