## Problems

- [今日头条2018校招后端方向（第二批）](https://www.nowcoder.com/test/8537209/summary)

## Solution

- a / 排序查询
- b / 我是用滑动窗口来做的
- c / dp
    ```
    dp[i][j] = 
        i == j      => 0
        i + 1 == j  => arr[j] - arr[i] - 1
        other       => dp[i + 1][j - 1] + arr[j] - arr[i] - (j - i)
    ```