class Solution {
public:
    int numDecodings(string s) {
        vector<int> decodes(s.size() + 1, 1);
        if (s[s.size()-1] == '0') decodes[s.size()-1] = 0;
        else decodes[s.size()-1] = 1;
        for (int i = s.size() - 2; i >= 0; i--){
            if (s[i] == '0'){
                decodes[i] = 0;
                continue;
            }
            decodes[i] = decodes[i+1];
            if ((s[i] - '0') * 10 + (s[i+1] - '0') <= 26) decodes[i] += decodes[i+2];
        }
        return decodes[0];
    }       
};
