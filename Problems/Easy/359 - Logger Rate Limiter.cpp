
// Question) 359. Logger Rate Limiter


// Implementation

// Using Unordered Map
// Time Complexity : O(1)
// Time Complexity : O(N)

class Logger {
private:
    unordered_map<string, int> mp;
    
public:
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) == mp.end()){
            mp[message] = timestamp;
            return true;
        }
        else{
            if(timestamp - mp[message] >= 10){
                mp[message] = timestamp;
                return true;
            }
            else return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
