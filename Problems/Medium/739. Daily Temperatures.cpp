
// Question) 739. Daily Temperatures


// Implementation

// same as finding the next greater element
// using stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> s;
        
        for(int itr = temperatures.size()-1; itr >= 0; itr--){
            while(!s.empty() && temperatures[itr] >= temperatures[s.top()]){
                s.pop();
            }
            if(s.empty()) res[itr] = 0;
            else res[itr] = s.top() - itr;
            
            s.push(itr);
        }
        return res;
    }
};
