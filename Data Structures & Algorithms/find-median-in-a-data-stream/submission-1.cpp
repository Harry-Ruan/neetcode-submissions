class MedianFinder {
public:
    priority_queue<int> maxhp;
    priority_queue<int, vector<int>, greater<int>> minhp;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if (maxhp.empty() && minhp.empty()) maxhp.push(num);
        else if (num < maxhp.top()) maxhp.push(num);
        else minhp.push(num);
        if (maxhp.size() > minhp.size() + 1){
            int tmp = maxhp.top();
            minhp.push(tmp);
            maxhp.pop();
        }
        else if (minhp.size() > maxhp.size()){
            int tmp = minhp.top();
            maxhp.push(tmp);
            minhp.pop();
        }
    }
    
    double findMedian() {
        if (maxhp.size() < minhp.size()){
            return minhp.top();
        }
        else if (minhp.size() < maxhp.size()){
            return maxhp.top();
        }
        else{
            return ((double) maxhp.top() + (double) minhp.top())/2;
        }
    }
};
