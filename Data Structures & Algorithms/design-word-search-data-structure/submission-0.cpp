class TrieNode{
public:
    bool end;
    unordered_map<int, TrieNode*> children;

    TrieNode(){
        end = false;
    }
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
            bool res = false;
            for(auto &child : cursor->children){
                res = (res || idxsearch(word, child.second, idx + 1));
            }
            return res;
        }
        else if (cursor->children.count(c - 'a')) cursor = cursor->children[c - 'a'];
        else cursor = nullptr;
        idx++;
        return idxsearch(word, cursor, idx);  
    }
};
