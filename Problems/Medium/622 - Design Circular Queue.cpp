
// Question) 622. Design Circular Queue


// Implementation

// Time Complexity = O(1), Space Complexity = O(N)

class MyCircularQueue {
public:
    int cap;
    deque<int> dq;
        
    MyCircularQueue(int k) {
        cap = k;    
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        dq.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        dq.pop_front();
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : dq.front();
    }
    
    int Rear() {
        return isEmpty() ? -1 : dq.back();
    }
    
    bool isEmpty() {
        return (dq.size() == 0) ? true : false;
    }
    
    bool isFull() {
        return (dq.size() == cap) ? true : false;
    }
};
