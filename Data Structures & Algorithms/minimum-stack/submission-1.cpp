class MinStack {
public:
    stack<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> todelete;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        pq.push(val);
    }
    
    void pop() {
        todelete[st.top()]++;
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        while (todelete.count(pq.top()) && todelete[pq.top()] > 0){
            todelete[pq.top()]--;
            pq.pop();
        }
        return pq.top();
    }
};
