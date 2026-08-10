# 題目名稱
Add Binary

## 題目連結

- LeetCode:https://leetcode.com/problems/add-binary/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/3

## 解題思路
第一眼的想法:
直接用 string 從後面一位加起來，加兩個數的位數&carry，111 就 1然後上一位加carry、兩個1就 0 然後加 carry、1個1就1、0個1就0


但其實不需要把每種情況分開判斷，可以統一成：
``sum = a[i] + b[j] + carry``  
目前這一位 = ``sum % 2``  
新的 carry = ``sum / 2``

因為 binary 是 base 2，所以 % 2 可以取得目前這一位，而 / 2 可以取得 carry。

如果其中一個 string 已經走完，就把那一邊當作 0。
## 演算法



## 複雜度

- Time: O(max(n, m))
- Space: O(max(n, m))  

其中 n、m 分別是 a 和 b 的長度。

## 實作細節
```
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += (a[i]-'0');
            }

            if (j >= 0) {
                sum += (b[j]-'0');
            }

            result.push_back((sum % 2) + '0');
            carry = sum / 2;

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
```

## 易錯點
- a[i] 和 b[j] 是 char，不是 integer。  
  所以要把：'0' '1'  
轉成：0,1  
可以使用：``a[i] - '0'``
- ``result`` 是 string，所以 ``push_back()`` 要放 char。
- while 條件不能只有：
``while (i >= 0 || j >= 0)``
因為最後可能還有 carry。

## 可以記住的 Pattern

模擬 carry。

對 base B 的加法，可以記：

目前 ``digit = sum % B``，
``carry = sum / B``

這題是 binary，所以 B = 2：

``digit = sum % 2``，``carry = sum / 2``

這個 pattern 之後遇到大數字字串相加、不同進位制加法時也會用到。