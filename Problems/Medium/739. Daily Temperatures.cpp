
// Question) 739. Daily Temperatures


// Implementation

// Naive Solution
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


// Efficient Solution
// using the res vector only to get the next greater element
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);        
        
        for(int itr = n-1; itr >= 0; itr--){
            int jtr = itr + 1;
            
            while(jtr < n && temperatures[itr] >= temperatures[jtr]){
                if(res[jtr] > 0) jtr = res[jtr] + jtr;
                else jtr = n;
            }
            
            if(jtr < n) res[itr] = jtr - itr;
        }        
        return res;
    }
};
