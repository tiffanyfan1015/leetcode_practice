# 題目名稱
Climbing Stairs

## 題目連結

- LeetCode:https://leetcode.com/problems/climbing-stairs/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/1

## 解題思路
每次只能走 1 階或 2 階。

要到第 i 階，最後一步只可能：

從第 `i - 1` 階走 1 步  
從第 `i - 2` 階走 2 步

## 演算法
dp [1] = 1  
dp [2] = 2  
從第 3 階開始：
dp[n] = dp[n-1] + dp[n-1]  
最後回傳 dp[n]

## 複雜度

- Time: O(n)
- Space: O(n)
(可以再變成 O(1) 如果每次都只記那兩個數)

## 實作細節
```
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i<=n; i++){
            dp[i] = dp[i-1] + dp [i-2];
        }
        
        return dp[n];
    }
};
```

## 易錯點
- 要處理 `n == 1`，否則直接使用 `dp[2]` 或假設第二階存在可能出錯。

## 可以記住的 Pattern
這題是 Fibonacci 型 DP：

目前狀態 = 前一個狀態 + 前兩個狀態

看到「第 `i` 個答案只依賴前幾個答案」時，可以先想 DP，再檢查是否能把 Space 從 `O(n)` 壓成 `O(1)`。