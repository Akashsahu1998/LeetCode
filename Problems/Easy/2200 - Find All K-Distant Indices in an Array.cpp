
// Question) 2200. Find All K-Distant Indices in an Array


// Implementation

// Time Complexity: O(N^2)
// Space Complexity: O(1), Not consdering the res vector, bcz that's a part of o/p

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        
        for(int itr = 0; itr < nums.size(); itr++){
            for(int jtr = 0; jtr < nums.size(); jtr++){
                if(abs(itr-jtr) <= k && nums[jtr] == key){
                    res.push_back(itr);
                    break;
                }
            }
        }
        
        return res;
    }
};
