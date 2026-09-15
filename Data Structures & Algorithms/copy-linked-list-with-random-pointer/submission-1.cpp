/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cursor = head;
        Node* dummy = new Node(-1);
        Node* creator = dummy;
        unordered_map<Node*, Node*> mp;
        while (cursor){
            creator->next = new Node(cursor->val);
            mp[cursor] = creator->next;
            cursor = cursor->next;
            creator = creator->next;
        }
        cursor = head;
        creator = dummy->next;
        while (cursor){
            creator->random = mp[cursor->random];
            cursor = cursor->next;
            creator = creator->next;
        }
        return dummy->next;
    }
};
