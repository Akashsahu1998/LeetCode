
// Question) 239. Sliding Window Maximum



// Implementation

// Naive Approach
// TLE will come
// Time Complexity = O(N*K), Space Complexity = O(1), we are considering output vector for space
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int itr = 0; itr <= nums.size()-k; itr++){
            int maxWindowValue = INT_MIN;
            for(int jtr = itr; jtr < itr+k; jtr++){
                maxWindowValue = max(maxWindowValue, nums[jtr]);
            }
            res.push_back(maxWindowValue);
        }
        return res;
    }
};


// https://www.youtube.com/watch?v=tCVOQX3lWeI&t=180s
// Efficient Approach
// using stack
// Traversing 2 times
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
                
        // we are finding the next greater element for all elements in the given array
        stack<int> s;
        vector<int> nextGreaterElementArr(n);        
        for(int itr = n-1; itr >= 0; itr--){
            while(!s.empty() && nums[s.top()] <= nums[itr]){
                s.pop();
            }
            
            if(s.empty()) nextGreaterElementArr[itr] = n;
            else nextGreaterElementArr[itr] = s.top();
            s.push(itr);
        }
        
        vector<int> res;
        
        int jtr = 0;
        for(int itr = 0; itr <= n-k; itr++){
            // this  jtr < itr condition is very important to keep the time complexity O(n) otherwise
            // in case of ascending order array the time complexity will be O(n*k).
            // I.E nums = [1,2,3]
            if(jtr < itr){
                jtr = itr;
            }
            while(nextGreaterElementArr[jtr] < itr+k){
                jtr = nextGreaterElementArr[jtr];
            }
            res.push_back(nums[jtr]);
        }
        return res;
    }
};



