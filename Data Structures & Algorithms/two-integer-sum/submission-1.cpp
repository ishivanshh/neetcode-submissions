class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>a;
        for(int i = 0; i < n;i++){
            a.push_back({nums[i],i});
        }
        sort(a.begin() , a.end());

        int left = 0;
        int right = n - 1;

        while(left < right){

            int sum = a[left].first + a[right].first;

            if(sum == target) {
                return {min(a[left].second , a[right].second), max(a[left].second , a[right].second)};
            } else if(sum > target){
                right--;
            } else left++;
        }
        return {};
    }
};
