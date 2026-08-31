class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        stack<int>st; // storing index
        int n = heights.size();
        for(int i = 0; i < n; i++){
            // if stack is not empty and curr element is smaller than prev 
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(heights[ele] * (nse - pse - 1) , maxarea);
            }
            st.push(i);
        }

        // if still elements left in stack...

        while(!st.empty()){
            int nse = n;
            int ele = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea , (nse - pse - 1) * heights[ele]);
        }
        return maxarea;
    }
};
