class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> postmp;
    unordered_map<int, unordered_set<int>> followmp;
    int total;
    Twitter() {
        total = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        total++;
        postmp[userId].push_back({total, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> maxhp;
        vector<int> res;
        followmp[userId].insert(userId);
        for (int follow : followmp[userId]){
            if (postmp.count(follow)){
                int sz = postmp[follow].size()-1;
                maxhp.push({postmp[follow][sz].first, postmp[follow][sz].second, follow, sz});
            }
        }
        while (res.size() < 10 && !maxhp.empty()){
            res.push_back(maxhp.top()[1]);
            int follow = maxhp.top()[2];
            int index = maxhp.top()[3];
            maxhp.pop();
            if (index-1 >= 0) maxhp.push({postmp[follow][index-1].first,postmp[follow][index-1].second, follow, index-1});
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followmp[followerId].count(followeeId)) followmp[followerId].erase(followeeId);
    }
};
