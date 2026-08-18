class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int missingno = 1;
        while (true) {
            bool flag = true;
            for (int& num : nums) {
                if (missingno == num) {
                    flag = false;
                    break;
                }
            }
            if (flag) return missingno;
            missingno++;
        }
    }
};