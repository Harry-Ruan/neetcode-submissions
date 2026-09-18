class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxhp;
        for (int i : stones){
            maxhp.push(i);
        }
        while (maxhp.size() > 1){
            int x = maxhp.top();
            maxhp.pop();
            int y = maxhp.top();
            maxhp.pop();
            if (x > y) maxhp.push(x-y);
        }
        if (maxhp.size() == 0) return 0;
        else return maxhp.top();
    }
};
