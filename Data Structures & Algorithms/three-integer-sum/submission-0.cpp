class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort 
        sort(nums.begin() , nums.end());
        // fix one element
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0; i < n-2; i++){
            // check & skip duplicates
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    ans.push_back({nums[i] , nums[left] , nums[right]});
                    left ++ ;
                    right --;

                    // skip duplicates pairs
                    while(left < right && nums[left] == nums[left - 1]){
                        left ++;
                    }
                    while(left < right && nums[right] == nums[right + 1]){
                        right --;
                    }
                }
                else if(sum > 0) right --;
                else left ++;
            }
        }
        return ans;
    }
};
