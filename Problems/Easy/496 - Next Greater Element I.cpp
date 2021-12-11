
// Question) 496. Next Greater Element I


// Implementation

// Time Complexity = O(N), Space Complexity = O(N)

// 1st Approach
// Using Map and Stack
// Traversing from back
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp;
        vector<int> res;
        
        for(int itr = nums2.size()-1; itr >= 0; itr--){
            while(!s.empty() && s.top() < nums2[itr]){
                s.pop();
            }
            if(s.empty()) mp[nums2[itr]] = -1;
            else mp[nums2[itr]] = s.top();
            s.push(nums2[itr]);
        }
        
        for(int itr = 0; itr < nums1.size(); itr++){
            res.push_back(mp[nums1[itr]]);
        }
        return res;
    }
};


// 2nd Approach
// Using Map and Stack
// Traversing from start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp;
        vector<int> res;
        
        for(int itr = 0; itr < nums2.size(); itr++){
            while(!s.empty() && nums2[itr] >= s.top()){
                mp[s.top()] = nums2[itr];
                s.pop();
            }
            s.push(nums2[itr]);
        }
        
        for(int itr = 0; itr < nums1.size(); itr++){
            mp[nums1[itr]] ? res.push_back(mp[nums1[itr]]) : res.push_back(-1);
        }
        
        return res;
    }
};
