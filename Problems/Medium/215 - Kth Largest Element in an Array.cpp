
// Question) 215. Kth Largest Element in an Array


// Implementation

// 1st Approach
// Using Sorting
// Time Complexity = O(NLogN), Space Complexity = O(1)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end(), greater<int>());
//         return nums[k-1];
//     }
// };


// 2nd Approach
// Using Priority Queue (Max Heap)
// Time Complexity = (O(N) + O(kLogN))  => O(NLogN)
// Space Complexity = O(N)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//      priority_queue<int> pq(nums.begin(), nums.end());
// 	    for(int itr = 1; itr < k; itr++) pq.pop();
// 	    return pq.top();
//     }
// };


// 3rd Approach
// Using Multi Set (Min Heap)
// Time Complexity = (O(N) + (N-K+1 Log N-K+1)) => O(NLogN)
// Space Complexity = O(k+1)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         multiset<int> mset;
//         for (int num : nums) {
//             mset.insert(num);
//             if (mset.size() > k) {
//                 mset.erase(mset.begin());
//             }
//         }
//         return *mset.begin();
//     }
// };


// 4th Approach
// Using Bubble Sort
// Time Complexity = O(N*K), Space Complexity = O(1)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for(int itr = 0; itr < k; itr++){
//             for(int jtr = 0; jtr < nums.size()-itr-1; jtr++){
//                 if(nums[jtr] > nums[jtr+1]){
//                     int temp = nums[jtr];
//                     nums[jtr] = nums[jtr+1];
//                     nums[jtr+1] = temp;
//                 }
//             }            
//         }
//         return nums[nums.size()-k];
//     }
// };



// 5th Approach
// Using Quick Select Algo

// this method is similar to quick sort, but quick sort cares about both half, but this algo cares about only single half, suppose it requires smallest element then it will move into left half and leave right half, but suppose it required greatest element then it will move into right half and leave left half.

// Time Complexity = O(N) Best Case, O(N^2) Worst Case
// Space Complexity = O(LogN) Best Case, O(N) Worst Case

// Best Case = [4,2,1,7,6] suppose we are finding, 3rd largest element
// Worst Case = [1,2,3,4,5] suppose we are finding, 1st largest element

class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int itr = low, jtr = high, pivot = nums[itr];
        
        while(itr < jtr){
            
            // moving itr until & unless the element at index itr is greater than pivot and itr is less than equal to high
            while(itr <= high && nums[itr] <= pivot) itr++;
            
            // moving jtr until & unless the element at index jtr is smaller than pivot and jtr is greater than equal to low
            while(jtr >= low && nums[jtr] > pivot) jtr--;
            
            // if itr is less than jtr, then swap
            if(itr < jtr) swap(nums[itr], nums[jtr]);
        }
        
        swap(nums[low], nums[jtr]);
        
        return jtr;
    }
        
    int findKthLargest(vector<int>& nums, int k) {
        // in index we are putting the index of the result, suppose we want 2nd largest so from the last2nd index
        // so we will do n-k so we can get the largest element from last
        int index = nums.size() - k, low = 0, high = nums.size()-1;
        
        while(true){
            // partition
            int pivotIndex = partition(nums, low, high);    

            // if pivotIndex is smaller than the index which we want, then increase low
            if(pivotIndex < index){
                low = low + 1;
            }   // if pivotIndex is greater than the index which we want, then decrease high
            else if(pivotIndex > index){
                high = high - 1;
            }   // if pivotIndex is equal to the index which we want, then we got the result
            else{
                return nums[pivotIndex];
            }
        }
        return -1;
    }
};
