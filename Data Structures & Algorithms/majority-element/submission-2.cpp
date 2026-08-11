class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int ele;
        for(int i =0; i < n;i++){
            if(cnt == 0){
                cnt = 1; // 3.count -> 1
                ele = nums[i]; // 1.count -> 1
            } else if (ele == nums[i]){ 
                cnt ++;
            } else {
                cnt --; // 2.count -> 0
            }
        }

        int cnt1 = 0;
        for(int i =0;i < n;i++){
            if(nums[i] == ele){
                cnt1++;
            }
        }

        if(cnt1 > (n/2)){
            return ele;
        }
        return -1;
    }
};