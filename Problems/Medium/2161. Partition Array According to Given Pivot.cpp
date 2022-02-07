
// Question) 2161. Partition Array According to Given Pivot


// Implementation

// 1st Approach
// Using 3 extra array
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        // taking small array to put the value which are less the pivot
        // big array to put the value which are greater than pivot
        // equal array to put the value which are equal to pivot
        vector<int> small, equal, big;
        
        for(auto a : nums){
            if(a < pivot) small.push_back(a);
            else if(a > pivot) big.push_back(a);
            else equal.push_back(a);
        }
        
        // clearning the nums, and later using it as a result purpose
        nums.clear();
        for(auto a : small) nums.push_back(a);
        
        for(auto a : equal) nums.push_back(a);
        
        for(auto a : big) nums.push_back(a);
        
        return nums;
    }
};
