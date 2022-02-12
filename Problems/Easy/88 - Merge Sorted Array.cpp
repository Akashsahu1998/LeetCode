
// Question) 88. Merge Sorted Array


// Implementation

// Naive Approach
// Time Complexity : O(n * m)
// Space Complexity : O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        // take two pointers, itr will point to nums1, and jtr will point to nums2
        int itr = 0, jtr = 0;
                
        while(itr < n && jtr < m){
            
            // if nums[itr] is greater than nums2[jtr], then swap each other
            if(nums1[itr] > nums2[jtr]) swap(nums1[itr], nums2[jtr]);
            
            // always increment itr by 1
            itr++;
            
            // maintain the sorted order of nums2, bcz we are swapping values, so it can happen that, nums2 can loose it sorted order, so we need to check it and maintain it everytime
            if(jtr+1 < m && nums2[jtr] > nums2[jtr+1]){
                int ktr = jtr;
                while(ktr+1 < m && nums2[ktr] > nums2[ktr+1]){
                    swap(nums2[ktr], nums2[ktr+1]);
                    ktr++;
                }
            }
        }
        
        // in last, just put all the values of nums2 into nums1
        while(jtr < m){
            nums1[itr++] = nums2[jtr++];
        }
    }
};
