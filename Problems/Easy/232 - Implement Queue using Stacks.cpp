
// Question) 232. Implement Queue using Stacks


// Implementation

// Time Complexity = Best Case : O(1) , Worst Case : O(N) i.e  push(1), push(2), push(3), push(4), push(5), pop()
// Space Complexity = O(N)

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    
    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int res = peek();
        st2.pop();
        return res;
    }
    
    int peek() {
        if(st2.empty()){
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty(); 
    }
};
