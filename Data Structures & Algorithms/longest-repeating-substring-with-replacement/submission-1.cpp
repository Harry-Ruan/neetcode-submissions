class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> fq;
        int cursz = 0;
        char mostfqchar;
        int mostfq = 0;
        int l = 0;
        int r = 0;
        while(r < s.size()){
            char cur = s[r];
            fq[cur]++;
            cursz++;
            if (fq[cur] > mostfq){
                mostfq = fq[cur];
                mostfqchar = cur;
            }
            while(cursz - mostfq > k){
                fq[s[l]]--;
                cursz--;
                l++;
            }
            r++;
        }
        return cursz;
    }
};
