class Solution {
public:
    // maximun element in the piles
    int findMax(vector<int> & piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }
    // calculation of total hrs 
    long long calculateTotalHours(vector<int>& piles ,int hourly){
        long long totalH = 0;
        for(int i = 0; i < piles.size(); i++){
            totalH += ceil((double)piles[i]/ (double)hourly);
        }
        return totalH;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while (low <= high){
            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if(totalH <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
