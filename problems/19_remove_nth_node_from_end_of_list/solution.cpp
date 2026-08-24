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