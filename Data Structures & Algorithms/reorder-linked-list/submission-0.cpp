class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. 寻找中点并切断前半段
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // 用于切断前半段
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = nullptr; // 切断前半段，防止产生环

        // 2. 反转后半段
        ListNode* c2 = reverse(slow);
        ListNode* c1 = head;

        // 3. 安全地交叉合并两个链表
        while (c1 && c2) {
            ListNode* nxt1 = c1->next;
            ListNode* nxt2 = c2->next;

            c1->next = c2;
            if (nxt1 == nullptr) break; // 前半段结束，避免覆盖 c2 的后续连接
            c2->next = nxt1;

            c1 = nxt1;
            c2 = nxt2;
        }
    }

    ListNode* reverse(ListNode* downhead) {
        ListNode* pre = nullptr;
        ListNode* cur = downhead;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre; // 循环结束时 pre 就是新头节点，无需多余的 downhead->next
    }
};