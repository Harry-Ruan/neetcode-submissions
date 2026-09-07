class TrieNode{
public:
    bool end;
    vector<TrieNode*> children;

    TrieNode() : children(26, nullptr), end(false) {}
};

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cursor = root;
        for (char c : word){
            if (!cursor->children[c - 'a']) cursor->children[c - 'a'] = new TrieNode();
            cursor = cursor->children[c - 'a'];
        }
        cursor->end = true;
    }
    
    bool search(string word) {
        bool res = idxsearch(word, root, 0);
        return res;
    }

    bool idxsearch(string word, TrieNode* cursor, int idx){
        if (!cursor) return false;
        if (idx == word.size()){
            if (cursor->end) return true;
            return false;
        }
        char c = word[idx];
        if (c == '.'){
            for(TrieNode* child : cursor->children){
                if (child != nullptr && idxsearch(word, child, idx + 1)) {
                    return true; 
                }
            }
            return false;
        }
        cursor = cursor->children[c - 'a'];
        idx++;
        return idxsearch(word, cursor, idx);  
    }
};

// half iteration, half recursion !!!
