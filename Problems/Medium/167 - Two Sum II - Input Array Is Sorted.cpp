
// Question) 167. Two Sum II - Input Array Is Sorted


// Implementation

// Using Two Pointer Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        
        while(low < high){
            int sum = numbers[low] + numbers[high];
            if(sum == target){
                return {low+1, high+1};
            }
            else if(sum > target){
                high--;
            }
            else{
                low++;
            }
        }
        
        return {};
    }
};
