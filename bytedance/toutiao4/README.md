## Problems

[今日头条2018校招后端方向（第四批）](https://www.nowcoder.com/test/8537039/summary)

## Solution

- a / 枚举所有的情况 => 推公式 + 注意数据范围
- b / 用一个 count 数据记录，0 - i 的字母状态 + 二分查找
- c / dp, dp[0] = -1
    - dp[i] = dp[i - 1] + 1
    - dp[i] += 1
    - dp[i] += dp[i - 1] - dp[pos[i] - 1] - 1
    - dp[i] += 1
    - **dp[i] = 2 * dp[i -  1] - dp[pos[i] - 1] + 2**