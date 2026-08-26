class MyStack {
public:
queue<int>q1, q2;
    MyStack() {}
    
    void push(int x) {
        // adding in q2
        q2.push(x);
        // push elemts from q1 -> q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        //swapping , elements got in q1.
        swap(q1,q2);
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */