
// Question) 362. Design Hit Counter


// Implementation


// 1st Approach
// Using Queue
// Time Complexity : O(N), in worst case, we might end up removing all the entries from the queue in getHits(), that's why its O(N), 
// Space Complexity : O(N)

class HitCounter {
private:
    queue<int> q;
    
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);    
    }
    
    int getHits(int timestamp) {
        while(!q.empty() && timestamp - q.front() >= 300){
            q.pop();
        }
        return q.size();
    }
};
