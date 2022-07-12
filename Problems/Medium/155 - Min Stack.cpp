
// Question) 155. Min Stack


// Implementation

// Using Stack
// Time Complexity : O(1)
// Space Complexity : O(N)

class MinStack {
private:
    stack<int> st;
    int curMinValue = INT_MAX;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(val <= curMinValue){
            st.push(curMinValue);
            curMinValue = val;
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top() == curMinValue){
            st.pop();
            curMinValue = st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return curMinValue;
    }
};


// Algo Steps
// 1) Use 1 stack and minValue var & try to push minValue with every value is greater than minValue.
// 2) whenver we are pushing value, check if its less than minValue, then push the minValue first after that value.
// 3) whenver we are poping value, check if its equal to minValue, then pop and put the top value into minValue, after that pop again.



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
