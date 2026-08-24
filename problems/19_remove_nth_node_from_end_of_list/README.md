# 題目名稱
Remove Nth Node From End of List

## 題目連結

- LeetCode:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/21

## 解題思路
第一眼想說先顛倒他，或是到尾再回來  
但這樣是不必要的操作

可以用快慢指標，讓 fast 比 slow 多走 n + 1 步。  
當 fast 到尾端時，slow 會停在要刪除節點的前一個。

## 演算法
快慢指標!
dummy node!!

1. 建立 ``dummy`` 指向 ``head``
2. ``slow``、``fast`` 都從 ``dummy`` 開始
3. ``fast`` 先走 n + 1 步
4. ``slow``、``fast` 一起往前
5. ``fast`` 到底時，刪除 ``slow->next``
6. 回傳 ``dummy.next``


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // fast 往前走 n+1 步
        for(int i=0; i<=n; i++){
            fast = fast->next;
        }

        // fast 到底的時候，slow 停在要刪除節點的前一個
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        // delete node(n)
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return dummy.next;
    }
};
```

## 易錯點
- ``fast`` 要先走 ``n + 1`` 步，才能讓 ``slow`` 停在目標節點的前一個。
- 使用 ``dummy`` 可以處理刪除 ``head`` 的情況。
- 刪除節點時要改前一個節點的 ``next``：
slow->next = slow->next->next;
- 最後回傳 ``dummy.next``，因為原本的 ``head`` 可能已被刪除。