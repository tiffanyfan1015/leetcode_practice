# 題目名稱
Search insert position

## 題目連結

- LeetCode: https://leetcode.com/problems/search-insert-position/
- Source issue: https://github.com/tiffanyfan1015/leetcode_practice/issues/6

## 解題思路
已排序的陣列 -> 可以用 Binary Search

## 演算法
Binary Search

## 複雜度

- Time: O(log n)
- Space: O(1)

Binary Search 每次會將搜尋範圍縮小一半，因此時間複雜度為 O(log n)。  
只使用 left、right、mid 等固定數量的變數，因此空間複雜度為 O(1)。

## 實作細節
cpp
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};
```

## 易錯點
- C++ vector 要用 ``nums.size()``
- 如果 ``nums[mid] == target``，這題可以直接回傳 ``mid``
- 如果最後找不到 ``target``，則回傳 ``left``
