
// Question) 2164. Sort Even and Odd Indices Independently


// Implementation

// 1st Approach
// Using two extra array
// Time Complexity : O(NLogN)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        // take two array odd & even
        vector<int> odd,even;
        
        // iterate over the list, and for even index add the value into even array, and for odd index add the value into odd array
        for(int itr = 0; itr < nums.size(); itr++){
            if(itr%2 == 0) even.push_back(nums[itr]);
            else odd.push_back(nums[itr]);
        }
        
        // sort the even array in ascending order
        sort(even.begin(), even.end());
        
        // sort the odd array in descending order
        sort(odd.begin(), odd.end(), greater<int>());
                
        // run the loop from 0 to nums.size(), and for even index of nums, put the value of even array, and for odd index of nums, put the value of odd array
        for(int itr = 0, i = 0, j = 0; itr < nums.size(); itr++){
            if(itr%2 == 0) nums[itr] = even[i++];
            else nums[itr] = odd[j++];
        }
        
        return nums;
    }
};



// 2nd Approach
// Using one extra array
// Time Complexity : O(NLogN)
// Space Complexity : O(N)

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr;
        
        // push the even index values into arr
        for(int itr = 0; itr < n; ){
            arr.push_back(nums[itr]);
            itr += 2;
        }
        
        // sort the arr in ascending order and place back into the even index of nums
        sort(arr.begin(), arr.end());
        for(int itr = 0, jtr = 0; itr < n; ){
            nums[itr] = arr[jtr++];
            itr += 2;
        }
        
        // clear the arr, so we can resuse it for odd index
        arr.clear();
        
        // push the odd index values into arr
        for(int itr = 1; itr < n; ){
            arr.push_back(nums[itr]);
            itr += 2;
        }
        
        // sort the arr into descending order and place back into the odd index of nums
        sort(arr.begin(), arr.end(), greater<int>());
        for(int itr = 1, jtr = 0; itr < n; ){
            nums[itr] = arr[jtr++];
            itr += 2;
        }
        
        return nums;
    }
};
