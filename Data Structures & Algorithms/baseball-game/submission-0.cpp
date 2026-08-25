class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int>stack;
        for(int i = 0; i < n;i++){
            string op = operations[i];

            if(op == "+"){
                int top = stack.back(); // last element
                stack.pop_back(); // delete last element

                int newtop= top + stack.back(); // sum of prev 2 
                stack.push_back(top); 
                stack.push_back(newtop); 
            } else if (op == "D"){
                stack.push_back(2* stack.back());
            } else if (op == "C"){
                stack.pop_back();
            } else stack.push_back(stoi(op));
        }
        return accumulate(stack.begin() , stack.end() , 0);
    }
};