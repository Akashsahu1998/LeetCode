
// Question) 225. Implement Stack using Queues


// Implementation

// Time Complexity = O(N), Space Complexity = O(N)

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        int returnValue = q.back();
        while(size-- > 1){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return returnValue;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.empty()) return true;
        return false;
    }
};

// Some base cases for understanding the pop functionality
// ["MyStack","push","push","top","pop","empty"]
// [[],[1],[2],[],[],[]]
// ["MyStack","push","pop","empty"]
// [[],[1],[],[]]
// ["MyStack","push","push","pop","top"]
// [[],[1],[2],[],[]]
