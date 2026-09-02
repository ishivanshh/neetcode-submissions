class Solution {
public:
    int maxPages(vector<int>& nums, int mid) {
        int stud = 1;
        int pagesStud = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pagesStud + nums[i] <= mid) {
                pagesStud += nums[i];
            } else {
                stud++;
                pagesStud = nums[i];
            }
        }
        return stud;
    }

    int splitArray(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int studentPerPage = maxPages(nums, mid);

            if (studentPerPage > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};