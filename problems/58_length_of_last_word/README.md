# 題目名稱
Length of Last Word

## 題目連結

- LeetCode:https://leetcode.com/problems/length-of-last-word/description/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/5

## 解題思路
只是要最後一個字的長度，所以可以直接從``尾端``搜尋

## 演算法
- 跳過字串最尾端的空白 
- 找到最後一個 word 後，往前算字元數量，直到遇到空白或到達字串開頭

## 複雜度

- Time: O(n)
- Space: O(1)

## 實作細節
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int count = 0;
        while(i >= 0 && s[i]==' '){
            i--;
        }
        while(i >= 0 && s[i]!=' '){
            count ++;
            i--;
        }
        return count;
    }
};
```

## 易錯點
- ``s[i]`` 的型別是 char，所以比較單一字元時要使用單引號：
``s[i] == ' '``
，而不是：``s[i] == " "``

- 存取 ``s[i]`` 之前，要先確認 i >= 0，否則可能發生 index 越界。
