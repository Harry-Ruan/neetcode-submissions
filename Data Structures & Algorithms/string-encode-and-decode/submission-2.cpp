class Solution {
public:

    string encode(vector<string>& strs) {
        string codestr = "";
        for (string s : strs){
            codestr += to_string(s.length());
            codestr += '#';
            for (char c : s){
                codestr += c;
            }
        }
        return codestr;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int cnt = 0;
        while(cnt < s.size()){
            string len = "";
            while(s[cnt] != '#'){
                len += s[cnt];
                cnt++;
            }
            cnt++;
            int l = stoll(len);
            string tmp = "";
            for (int i = cnt; i < cnt + l; i++){
                tmp += s[i];
            }
            res.push_back(tmp);
            cnt += l;
        }
        return res;
    }
};
