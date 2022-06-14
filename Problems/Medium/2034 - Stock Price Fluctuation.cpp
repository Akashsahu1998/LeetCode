
// Question) 2034. Stock Price Fluctuation


// Implementation

// Using Unordered Map & Multiset
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

class StockPrice {
private:
    // contains the price, so from here we can get the maximum and minimum prices
    multiset<int> st;
    
    // timestamp, price
    unordered_map<int, int> mp;
    
    // to hold the current(latest) timeStamp
    int maxTimeStamp = -1;
    
public:
    StockPrice() {        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end()){
            st.erase(st.find(mp[timestamp]));
        }
        mp[timestamp] = price;
        st.insert(price);
        
        maxTimeStamp = max(maxTimeStamp, timestamp);
    }
    
    int current() {
        return mp[maxTimeStamp];
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
