# 題目名稱
Palindrome Linked List

## 題目連結

- LeetCode: https://leetcode.com/problems/palindrome-linked-list/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/20

## 解題思路
一開始的想法是，用一個 vector 先把所有數字都記下來  
然後從左和從右有兩個 pointer 開始往中間  
比較他們是不是一樣的  
如果不一樣就跳出 然後回傳 false  
都一樣就是回傳 true  
但這樣 Space O(n)，有 Space O(1) 的作法 ->

1. 用 fast / slow pointer 找 linked list 中點
2. 反轉後半段
3. 比較前半段和反轉後的後半段

## 演算法

1. slow 每次走一步，fast 每次走兩步
2. fast 到尾端時，slow 會在中間
3. 從 slow 開始反轉後半段 linked list
4. left 從 head 開始，right 從反轉後的 head 開始
5. 逐一比較兩邊的 val
6. 有不同就回傳 false
7. 比較完成後回傳 true

## 複雜度

- Time:O(n)
- Space:O(1)

## 實作細節
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1. find mid point
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // compare left & right
        ListNode* left = head;
        ListNode* right = prev;

        while (right != nullptr) {
            if (left->val != right->val) {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
};
```

## 易錯點
**可以記住的 Pattern**

Linked List 題常見組合：

fast / slow
→ 找中點

reverse linked list
→ 改變方向

兩個 pointer
→ 比較兩段