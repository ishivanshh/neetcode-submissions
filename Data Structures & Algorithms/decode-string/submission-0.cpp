class Solution {
public:
    string decodeString(string s) {
        stack<pair<string , int>>st;
// using single stack instead of double stack.
        string curr = ""; // stores curr 
        int num = 0; // curr num

        for(char c : s){
            if(isdigit(c)){
                num = num * 10 + (c - '0'); // keeps digit in same order
            } else if (c == '['){
                st.push({curr , num}); // stores curr number and string in stack
                curr = ""; // then reset both curr and num 
                num = 0;
            } else if (c == ']'){ // tops out both number and last entered string 
                auto [prev , k] = st.top();
                st.pop(); 
                // untill k gets zero
                while(k--){
                    // add curr string to prev string k times
                    prev += curr;
                }
                // set prev as curr value in stack
                curr = prev;
            }
            // if getting only string keep on adding in curr
            else curr += c; 
        }
        return curr;
    }
};