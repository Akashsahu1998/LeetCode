
// Question) 41. First Missing Positive


// Implementation

// 1st Approach
// Brute Force
// Using array as a map
// Time Complexity = O(N),
// Space Complexity = O(N)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n+2, 0); // taking n+2 to handle base case like this, i.e => [1,2,3]
        
        for(int itr = 0; itr < n; itr++){
            
            // this condition bcz, we don't want to calculate frequency of negative element and the element more than n
            if(nums[itr] >= 1 && nums[itr] <= n){
                mp[nums[itr]]++;
            }
        }
        
        // starting from 1, bcz we have to find the first positive number from 1
        for(int itr = 1; itr <= n+1; itr++){
            if(mp[itr] == 0) return itr;
        }
        
        return -1;
    }
};


// 2nd Approach
// Efficient Solution
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int itr = 0; itr < n; itr++){
            
            // idea is to put all the elements into their equal index(assuming index from 1), i.e 2 will be on (2 - 1)index, like this
            // neglect all numbers which are less than 1, and all numbers which are greater than n, and
            // if current nums[itr] is not equal to (nums[nums[itr] - 1]) value, then do swap
            // with this (nums[itr] != nums[nums[itr] - 1]) also handling the case i.e [1,1]
            // its 0 based indexing that's why using nums[itr] - 1             
            while((nums[itr] >= 1 && nums[itr] <= n) && (nums[itr] != nums[nums[itr] - 1])){
                int pos = nums[itr] - 1;                
                swap(nums[itr], nums[pos]);
            }
        }
        
        // checking if any element is not equal to their current index then it means that element is missing
        for(int itr = 0; itr < n; itr++){
            if(itr+1 != nums[itr]) return itr+1;
        }
        
        // returning n+1 bcz, i.e = [1,2,3] then ans will be 4 only
        return n+1;
    }
};
