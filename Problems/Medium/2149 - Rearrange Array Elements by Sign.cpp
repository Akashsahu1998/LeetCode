
// Question) 2149. Rearrange Array Elements by Sign


// Implementation

// 1st Approach
// Using 2 extra array's
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg, pos;
        int n = nums.size();
        
        // putting negative elements into neg array, and positive elements into pos array
        for(int itr = 0; itr < n; itr++){
            if(nums[itr] < 0) neg.push_back(nums[itr]);
            else pos.push_back(nums[itr]);
        }
        
        // result vector
        vector<int> res;
        
        // iterating and pusing even index as a positive value into res, and odd index as a negative value into res
        for(int itr = 0, jtr = 0, ktr = 0; itr < n; itr++){
            if(itr%2) res.push_back(neg[ktr++]);
            else res.push_back(pos[jtr++]);
        }
        
        return res;
    }
};



// 2nd Approach
// Efficient
// No extra array, only one array to store the result
// only 1 time traversal
// Time Complexity = O(N)
// Space Complexity = O(N), we are considering result vector as a space here, otherwise its O(1)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        // we know that, positive elements will always be on even index and negative elements will always be on odd index
        int n = nums.size(), posIndex = 0, negIndex = 1;

        // result vector
        vector<int> res(n);
        
        // iterating over the element
        for(int itr = 0; itr < n; itr++){
            
            // negative element
            if(nums[itr] < 0){
                res[negIndex] = nums[itr];
                negIndex += 2;
            }
            else{   // positive element
                res[posIndex] = nums[itr];
                posIndex += 2;
            }
        }
        
        return res;
    }
};
