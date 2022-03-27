
// Question) 2215. Find the Difference of Two Arrays


// Implementation

// Using Unordered Map
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        
        for(auto a : nums2){
            mp[a]++;
        }
        
        vector<int> temp;
        vector<vector<int>> ans;
        for(auto a : nums1){
            if(mp[a] == 0){
                temp.push_back(a);
                mp[a]++;
            }
        }
        
        ans.push_back(temp);
        temp.clear();
        mp.clear();
        
        for(auto a : nums1){
            mp[a]++;
        }
        
        for(auto a : nums2){
            if(mp[a] == 0){
                temp.push_back(a);
                mp[a]++;
            }
        }
        
        ans.push_back(temp);
        return ans;
    }
};

