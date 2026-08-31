class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int hash[256] = {0};

        int l = 0, r = 0;
        int cnt = 0;

        int minlen = 100000;
        int sindex = -1;

        // Store frequency of characters required from t
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {

            // If this character is still needed,
            // it contributes to satisfying t
            if (hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            // Try to shrink the window
            while (cnt == m) {

                // Update minimum window
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }

                // Remove s[l] from the window
                hash[s[l]]++;

                // If we removed a required character,
                // the window is no longer valid
                if (hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};


