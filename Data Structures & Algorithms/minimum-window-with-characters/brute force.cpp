

string minWindow(string s, string t) {

    unordered_map<char, int> required;

    // Frequency of characters required from t
    for (char c : t) {
        required[c]++;
    }

    int n = s.length();

    int minLen = INT_MAX;
    int startIndex = -1;

    // Choose starting point
    for (int i = 0; i < n; i++) {

        unordered_map<char, int> current;

        // Extend the substring using j
        for (int j = i; j < n; j++) {

            current[s[j]]++;

            // Check whether current window contains
            // all characters required by t
            bool valid = true;

            for (auto it : required) {

                char ch = it.first;
                int needed = it.second;

                if (current[ch] < needed) {
                    valid = false;
                    break;
                }
            }

            // If valid, update answer
            if (valid) {

                int len = j - i + 1;

                if (len < minLen) {
                    minLen = len;
                    startIndex = i;
                }
            }
        }
    }

    if (startIndex == -1) {
        return "";
    }

    return s.substr(startIndex, minLen);
}
