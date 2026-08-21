class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(int i = 0; i < n ; i++){
            st.insert(nums[i]);
        }
        int ind = 0;
        for(int val : st) {
            nums[ind++] = val;
        }
        return st.size();
    }
};