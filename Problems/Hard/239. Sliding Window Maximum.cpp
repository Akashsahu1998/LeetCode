
// Question) 239. Sliding Window Maximum



// Implementation

// 1st Approach
// Naive Approach
// TLE will come
// Time Complexity = O(N*K), Space Complexity = O(1), we are not considering output vector for space
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


// 2nd Approach
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
            // this (jtr < itr) condition is very important to keep the time complexity O(n) otherwise
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


// 3rd Approach
// https://www.youtube.com/watch?v=CZQGRp93K4k&t=153s
// Most Efficient Approach
// using dequeue
// Traversing 1 time
// Time Complexity : (O(N) + O(N)) => O(N),  N elements we are iterating, and N element we are inserting & deleting in queue

// Space Complexity : O(K), max to max only K elements we are putting into dequeue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for(int itr = 0; itr < nums.size(); itr++){
            // removing the index which is going out of our window
            if(!dq.empty() && dq.front() == itr-k) dq.pop_front();
            
            // pop till the coming element is greater
            while(!dq.empty() && nums[dq.back()] < nums[itr]){
                dq.pop_back();
            }
            
            // push the current element, bcz it can be a bigger element in future, bcz back elements will pop once they will go out of window
            dq.push_back(itr);
            
            // since we are iterating from 0th index that's why this if condition
            if(itr >= k-1) res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};



