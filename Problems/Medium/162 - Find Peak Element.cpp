
// Question) 162. Find Peak Element


// Implementation

// 1st Approach
// Brute Force
// Traversing the whole array, and checking for left and right index
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        for(int itr = 1; itr < n; itr++){
        if(itr == n-1){            
            if(arr[itr-1] < arr[itr])
             return itr;
        }
        else{
            if(arr[itr-1] < arr[itr] && arr[itr] > arr[itr+1])
             return itr;
         }
        }
       return 0;
    }
};
