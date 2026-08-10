# 題目名稱
Plus one

## 題目連結

- LeetCode: https://leetcode.com/problems/plus-one/description/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/4

## 解題思路
第一眼的想法:檢查最後一碼，如果不是9就直接輸出，最後一個 digit + 1 ；如果是9的話，就變成0，幫前面那個 digit +1，也是檢查是不是9，是的話就繼續往前  
but 要怎麼幫最前面那位多加位數?

## 演算法
注意: 全部都是 9 的話，可以把 ``digit[0] = 1``，最後面再 ``digits.push_back(0);``

## 複雜度

- Time:O(n)
- Space:O(1)

## 實作細節
cpp
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i>=0; i--){
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
```

## 易錯點
- 遇到不是 9 的 digit 後，可以直接 +1 並 return，不需要繼續檢查前面的 digit。
- 遇到「從低位開始、可能一路進位到高位」的題目，可以優先考慮從陣列尾端往前處理。