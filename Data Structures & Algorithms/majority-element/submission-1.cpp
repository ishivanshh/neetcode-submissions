class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int maxCount = 0;
        unordered_map<int, int>count;

        for(int i = 0; i < n; i++){
            count[nums[i]]++;
            if(count[nums[i]] > maxCount){
                res = nums[i];
                maxCount = count[nums[i]];
            }
        }
        return res;
    }
};