class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;

        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (m*n) - 1;
        while(low <= high){
            int mid = (low + (high - low) / 2);
            // matrix[5/4][5%4] => [1,1]
            if(matrix[mid/m][mid%m] == target) return true;
            else if(matrix[mid/m][mid%m] < target) {
                low = mid + 1;
            }  else high = mid - 1;
        }
        return false;
    }
};
