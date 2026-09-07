class TrieNode{
public:
    bool end;
    TrieNode* children[26];

    TrieNode(){
        end = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    
};


class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cursor = root;
        for (char c : word){
            if (!cursor->children[c - 'a']) cursor->children[c - 'a'] = new TrieNode();
            cursor = cursor->children[c - 'a'];
        }
        cursor->end = true;
    }
    
    bool search(string word) {
        TrieNode* cursor = root;
        for (char c : word){
            cursor = cursor->children[c - 'a'];
            if (!cursor) return false;
        }
        if (cursor->end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cursor = root;
        for (char c : prefix){
            cursor = cursor->children[c - 'a'];
            if (!cursor) return false;
        }
        return true;
    }
};

