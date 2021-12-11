
// Question) 503. Next Greater Element II


// Implementation

// Using Stack
// Time Complexity = O(2N), Space Complexity = O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;        
        vector<int> res(n, -1);
        for(int itr = 2*n-1; itr >= 0; itr--){
            while(!s.empty() && s.top() <= nums[itr%n]) s.pop();
            if(!s.empty()) res[itr%n] = s.top();
            s.push(nums[itr%n]);
        }
        return res;
    }
};
