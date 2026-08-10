class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,int>checks;
        for(int i =0; i < s.length() ; i++){
            checks[s[i]]++;
            checks[t[i]]--;
        }

        for(auto ch : checks){
            if(ch.second != 0) return false;
        }
        return true;
    }
};
