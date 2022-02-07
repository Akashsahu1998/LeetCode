
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



// 2nd Approach
// Using 1 extra array
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    // always starting low from 0, bcz we need to enter small element from 0th index
    // incrementing same when a is less than pivot, bcz the total number of element which are smaller than pivot, from there we need to start inserting same number
    // decrementing high when a is greater than pivot, bcz the total number of element which are greater than pivot, from the last, we need to start inserting high number
    
    vector<int> pivotArray(vector<int>& nums, int pivot) {        
        
        int low = 0, same = 0, high = nums.size();
        
        for(auto a : nums){
            if(a < pivot) same++;
            else if(a > pivot) high--;
        }
        
        vector<int> res(nums.size());
        for(auto a : nums){
            if(a < pivot) res[low++] = a;
            else if(a > pivot) res[high++] = a;
            else res[same++] = a;
        }
        
        return res;
    }
};
