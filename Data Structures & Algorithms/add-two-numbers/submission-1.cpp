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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool proceed = false;
        ListNode* cursor1 = l1;
        ListNode* cursor2 = l2;
        /* ListNode* prev1 = nullptr;
        ListNode* next1 = cursor1->next;
        while (next1){
            cursor1->next = prev1;
            prev1 = cursor1;
            cursor1 = next1;
            next1 = next1->next;
        }
        cursor1->next = prev1;
        ListNode* prev2 = nullptr;
        ListNode* next2 = cursor2->next;
        while (next2){
            cursor2->next = prev2;
            prev2 = cursor2;
            cursor2 = next2;
            next2 = next2->next;
        }
        cursor2->next = prev2; */
        ListNode* dummy = new ListNode(-1);
        ListNode* cursor = dummy;
        while (cursor1 && cursor2){
            int cur = (cursor1->val + cursor2->val + proceed);
            if (cur / 10 > 0) proceed = true;
            else proceed = false;
            cursor->next = new ListNode(cur % 10);
            cursor1 = cursor1->next;
            cursor2 = cursor2->next;
            cursor = cursor->next;
        }
        while (cursor1 || cursor2){
            if (cursor1){
                int cur = (cursor1->val + proceed);
                if (cur / 10 > 0) proceed = true;
                else proceed = false;
                cursor->next = new ListNode(cur % 10);
                cursor1 = cursor1->next;
                cursor = cursor->next;
            }
            else{
                int cur = (cursor2->val + proceed);
                if (cur / 10 > 0) proceed = true;
                else proceed = false;
                cursor->next = new ListNode(cur % 10);
                cursor2 = cursor2->next;
                cursor = cursor->next;
            }
        }
        if (proceed) cursor->next = new ListNode(1);
        return dummy->next;
    }
};
