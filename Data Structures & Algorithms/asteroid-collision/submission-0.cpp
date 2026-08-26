class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        
        for(int asteroid : asteroids){
            bool alive = true;
            // prev element is +ve and curr is -ve and stack notempty
            while(alive && !st.empty() && st.back() > 0 && asteroid < 0){
                if(st.back() < -asteroid){
                    st.pop_back();
                } else if(st.back() == - asteroid){
                    st.pop_back();
                    alive = false;
                } else alive = false;
            }
            if(alive) st.push_back(asteroid);
        }
        return st;
    }
};