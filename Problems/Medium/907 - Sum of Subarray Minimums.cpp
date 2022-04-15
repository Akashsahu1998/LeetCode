
// Question) 907. Sum of Subarray Minimums


// Implementation


// Naive Approach
// Time Complexity = O(N^2)
// Space Complexity = O(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            int minVal = arr[i];
            for(int j = i; j < arr.size(); j++){
                minVal = min(minVal, arr[j]);
                sum = (sum + minVal) % 1000000007;
            }
        }
        
        return sum;
    }
};
