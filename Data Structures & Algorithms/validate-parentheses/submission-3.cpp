class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s){
            if (isClose(c)){
                // 1. empty 2. front is open of
                if (st.empty() || st.top() != openOf(c)){
                    return false;
                }
                st.pop();
            } 
            else st.push(c); // is open
        }
        if (st.empty()) return true;
        return false;
    }

    char openOf(char c){
        if (c == ']') return '[';
        if (c == '}') return '{';
        if (c == ')') return '(';
    }

    bool isClose(char c){
        return (c == ']' || c == ')' || c == '}');
    }
};
