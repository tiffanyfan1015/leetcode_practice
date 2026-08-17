# 題目名稱
Sqrt(x)

## 題目連結

- LeetCode:https://leetcode.com/problems/sqrtx/description/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/2

## 解題思路
第一眼解法：i 相乘，看什麼時候超過 x  
但是 ``i * i`` 可能 integer overflow  
而且時間複雜度為 O(sqrt(x))  

**優化想法**：Binary Search

## 演算法
每次計算 mid：

如果 mid² == x，直接回傳 mid
如果 mid² < x，代表答案可能是 mid 或更大的數字，往右搜尋
如果 mid² > x，代表 mid 太大，往左搜尋

如果 x 不是完全平方數，Binary Search 結束後：

right = 最大的平方 <= x 的整數
left  = 第一個平方 > x 的整數

因此最後回傳 right。

## 複雜度

- Time: O(log x)
- Space: O(1)

## 實作細節
```
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            }
            else if (square < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return right;
    }
};
```

## 易錯點
直接 ``i * i`` 可能 integer overflow
