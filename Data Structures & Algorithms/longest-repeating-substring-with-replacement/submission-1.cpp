class Solution {
   public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        int maxf = 0;
        unordered_map<char, int> count;
        // sliding window move r untill winodw is valid 

        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            // as window becomes invalid decrease the freq of l and move l ++
            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
