class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxheap;
        queue<pair<int, int>> waiting;
        int cnt = 0;
        vector<int> chars(26, 0);
        for (char c : tasks){
            chars[c-'A']++;
        }
        for (int i = 0; i < 26; i++){
            if (chars[i]) maxheap.push(chars[i]);
        }
        while(!maxheap.empty() || !waiting.empty()){
            if (!waiting.empty()){
                if (maxheap.empty()){
                    cnt = waiting.front().second;
                    maxheap.push(waiting.front().first);
                    waiting.pop();
                }
                else if (cnt == waiting.front().second){
                    maxheap.push(waiting.front().first);
                    waiting.pop();
                }
            }
            if (!maxheap.empty()){
                cnt++;
                if (maxheap.top()-1) waiting.push({maxheap.top()-1, cnt + n});
                maxheap.pop();
            }
        }
        return cnt;
    }
};

// the type of char is not important
