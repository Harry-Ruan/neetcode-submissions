class DLNode{
public:
    DLNode* next;
    DLNode* prev;
    int val;

    DLNode(int idx){
        val = idx;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
public:
    int cap;
    int sz;
    DLNode* root;
    DLNode* back;
    unordered_map<int, int> mp;
    unordered_map<int, DLNode*> lis;
    

    LRUCache(int capacity) {
        cap = capacity;
        sz = 0;
        root = nullptr;
        back = nullptr;
    }
    
    int get(int key) {
        if (mp.count(key)){
            moveback(lis[key]);
            return mp[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (!mp.count(key)){
            DLNode* newNode = new DLNode(key);
            if (!root || !back){
                root = newNode;
                back = newNode;
            }
            else{
                back->next = newNode;
                newNode->prev = back;
                back = newNode;
            }
            sz++;
            mp[key] = value;
            lis[key] = newNode;
        }
        else{
            moveback(lis[key]);
            mp[key] = value;
        }
        if (sz > cap){
            mp.erase(root->val);
            lis.erase(root->val);
            if (root->next){
                DLNode* tmp = root->next;
                root->next->prev = nullptr;
                root->next = nullptr;
                root = tmp;
            }
            sz--;
        }
    }

    void moveback(DLNode* cur){
        if (cur == back) return;
        else if (cur == root) {
            DLNode* tmp = root->next;
            back->next = root;
            root->prev = back;
            root->next->prev = nullptr;
            root->next = nullptr;
            back = root;
            root = tmp;
        }
        else{
            DLNode* prev = cur->prev;
            DLNode* next = cur->next;
            if (prev) prev->next = next;
            if (next) next->prev = prev;
            cur->next = nullptr;
            cur->prev = back;
            back->next = cur;
            back = cur;
        }
    }
};
