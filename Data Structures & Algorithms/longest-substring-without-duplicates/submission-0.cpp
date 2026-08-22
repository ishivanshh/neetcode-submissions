class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>set;
        int l = 0;
        int res  =0;
        for(int r = 0; r < s.size();r++){
            while(set.contains(s[r])){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(res , r - l + 1);
        }
        return res;
    }
};
