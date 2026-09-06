class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int resl = l;
        int resr = r;
        int h = min (heights[l], heights[r]);
        int maximum = h * (r - l);
        while(l < r){
            if (heights[l] > heights[r]){
                r--;
            }
            else{
                l++;
            }
            int curheight = min(heights[l], heights[r]);
            int curwidth = r - l;
            if (curwidth * curheight > maximum){
                resl = l;
                resr = r;
                maximum = curwidth * curheight;
            }
        }
        return maximum;
    }
};
