class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int>& nums, int start, int end) {
        if(start < end) {
            int pindex = partition(nums, start, end); // for middle element
            quickSort(nums, start, pindex - 1); // left side
            quickSort(nums, pindex + 1, end); // right side
        }
    }
    int partition(vector<int>& nums, int st, int end) {
        int pivot = nums[end];
        int idx = st-1;
        for(int j = st ; j < end; j++){
            if(nums[j] <= pivot){
                idx++;
                swap(nums[j] , nums[idx]);
            }
        }
        idx++;
        swap(nums[end] , nums[idx]);
        return idx;
    }
};