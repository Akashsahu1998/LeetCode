
// Question) 346. Moving Average from Data Stream


// Implementation

// Using Queue
// Time Complexity = O(1)
// Space Complexity = O(N)

class MovingAverage {
private:
    int totalSum = 0, maxWindowSize = 0;
    queue<int> q;
    
public:
    MovingAverage(int size) {
        maxWindowSize = size;
    }
    
    double next(int val) {
        totalSum += val;
        q.push(val);
        if(q.size() > maxWindowSize){
            totalSum -= q.front();
            q.pop();
        }
        
        return (double)totalSum / q.size();
    }
};
