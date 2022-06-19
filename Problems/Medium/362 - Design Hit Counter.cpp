
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



// Consider the follow up, where we have multiple hits arriving at the "same" timestamps. We can optimize Approach 1 even further

// 2nd Approach
// Using Queue as a Deque
// Time Complexity : O(N), in worst case, we might end up removing all the entries from the queue in getHits(), that's why its O(N), 
// Space Complexity : O(N)

class HitCounter {
private:
    // timestamp, freq of that timestamp
    queue<pair<int, int>> dq;
    int size = 0;
    
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        // checking if that timestamp is already present into the dequeue or not
        // if present so just increase the frequency of that timestamp
        // otherwise insert the new entry as frequency 1 for the new timestamp
        if(!dq.empty() && dq.back().first == timestamp){
            dq.back().second++;
        }
        else dq.push({timestamp, 1});
        size++;
    }
    
    int getHits(int timestamp) {
        while(!dq.empty() && timestamp - dq.front().first >= 300){
            size -= dq.front().second;
            dq.pop();
        }              
        return size;
    }
};
