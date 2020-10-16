
// 1st Method

class Solution {
private:
    const vector<int> collection = {
        12, 23, 34, 45, 56, 67, 78, 89,
        123, 234, 345, 456, 567, 678, 789,
        1234, 2345, 3456, 4567, 5678, 6789,
        12345, 23456, 34567, 45678, 56789,
        123456, 234567, 345678, 456789,
        1234567, 2345678, 3456789,
        12345678, 23456789,
        123456789
    };
    
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(const auto& num : collection) {
            if(num > high) break;
            else if (num >= low) res.push_back(num);
        }
        return res;
    }
};


// 2nd Method

class Solution {
public:    
    void bfs(int itr, int low, int high, set<int>& st) {
            if(itr % 10 == 9)
            return;
            
            itr = itr * 10 + (itr % 10 + 1);
            if(itr > high)
            return;
    
            if(itr >= low && itr <= high)
            st.insert(itr);
            
            bfs(itr, low, high, st);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        set<int> st;
        
        for(int itr = 1; itr < 9; itr++)
        bfs(itr, low, high, st);
        
        for(int itr : st)
        ans.push_back(itr);
        
        return ans;
    }
};


