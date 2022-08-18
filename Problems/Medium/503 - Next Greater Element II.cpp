
// Question) 503. Next Greater Element II


// Implementation

// 1st Approach
// Using Stack
// Only 2 traversal of array
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        
        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            st.push(nums[i]);
        }
        
        for(int i = nums.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            
            st.push(nums[i]);
        }
        
        return res;
    }
};


// 2nd Approach
// Using Stack
// Only 2 traversal of array
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        int n = nums.size();
        
        for(int i = n*2-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            
            if(st.empty()){
                res[i%n] = -1;
            }
            else{
                res[i%n] = st.top();
            }
            
            st.push(nums[i%n]);
        }
        
        return res;
    }
};
