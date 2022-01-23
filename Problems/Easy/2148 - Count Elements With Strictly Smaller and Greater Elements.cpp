
// Question) 2148. Count Elements With Strictly Smaller and Greater Elements


// Implementation

// 1st Arpproach
// Using sorting
// Time Complexity = O(NLogN)
// Space Complexity = O(1)
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        
        // sort the array
        sort(nums.begin(), nums.end());
        
        // we know that array is sorted, so
        // taking small element as a first index of the array
        // taking big element as a last index of the array
        int small = nums[0], big = nums[n-1];
        
        // store the result count
        int count = 0;
        
        // if any element is having smaller and greater element, then increase the count
        for(int itr = 1; itr < n-1; itr++){
            if(nums[itr] > small && nums[itr] < big) count++;
        }
        return count;
    }
};



// 2nd Arpproach
// Efficient Solution
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
                
        // finding the small and big element from the array using predefined function
        int small = *min_element(nums.begin(), nums.end());
        int big = *max_element(nums.begin(), nums.end());
        
        // store the result count
        int count = 0;
        
        // if any element is having smaller and greater element, then increase the count
        for(int itr = 0; itr < n; itr++){
            if(nums[itr] > small && nums[itr] < big) count++;
        }
        return count;
    }
};
