class Solution {
public:
// function of both freq to check they are same or not.
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i =0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0}; // only lowercase
        // s1 => freq count.
        for(int i =0; i < s1.length() ; i++){
            freq[s1[i]- 'a']++;
        }
        // same as s1
        int windsize = s1.length();

        for(int i =0; i < s2.length(); i++){
            int windIdx = 0;
            int idx = i , windFreq[26] = {0};
            // map freq of every char in to second hashmap , then check
            while(windIdx < windsize && idx < s2.length()){
                windFreq[s2[idx] - 'a']++;
                windIdx++; 
                idx++;
            }

            if(isFreqSame(freq , windFreq)){ // found
                return true;
            }
        }
        return false;
    }
};