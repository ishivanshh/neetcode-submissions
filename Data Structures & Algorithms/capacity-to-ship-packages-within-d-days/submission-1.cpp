class Solution {
public:
    // find the max element as this will be starting point of seaching
    int findMax(vector<int> & weights){
        int maxi = INT_MIN;
        for(int i = 0; i < weights.size(); i++){
            maxi = max(weights[i], maxi);
        }
        return maxi;
    };

    // calculate the load that can ship with this capacity
    int findloads(vector<int> weights , int capacity){
        int days = 1 , load = 0;
        for( int i = 0 ; i < weights.size() ; i++){
            if(load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            } else load += weights[i];
        }
        return days;
    }
    // applying binary search on asnwers as we got range..
    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMax(weights);
        int high = accumulate(weights.begin() , weights.end() , 0);

        while(low <= high){
            
            int mid = low + (high - low) /2 ;
            int noOfDays = findloads(weights , mid);
            if(noOfDays <= days){
                high = mid - 1;
            } else low = mid + 1;
        }    
        return low;
    }
};