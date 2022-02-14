
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


// Efficient Approach
// Time Complexity : O(N+M) + O(NlogN) + O(MlogM) => O((N+M)log(N+M))
// Space Complexity : O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        // take 3 pointers, itr will point to nums1, and jtr will point to nums2, and ktr will start from nums1 end
        int itr = 0, jtr = 0, ktr = n - 1;
   
        // run till itr is less than equal to ktr, and jtr is less than m
        while (itr <= ktr && jtr < m) {
            
            // we are doing this, bcz we know the fact that both arr are sorted
            // if nums1[itr] is greater than nums2[jtr], then just increment itr by 1
            if (nums1[itr] < nums2[jtr])
                itr++;
            else {  // otherwise just swap nums1[ktr] and nums2[jtr], and decrement ktr by 1 & increment jtr by 1
                swap(nums2[jtr++], nums1[ktr--]);
            }
        }
       
        // Sort first array
        sort(nums1.begin(), nums1.begin() + n);
       
        // Sort second array
        sort(nums2.begin(), nums2.end());
        
        // in last, just put all the values of nums2 into nums1
        itr = n, jtr = 0;
        while(jtr < m){
            nums1[itr++] = nums2[jtr++];
        }        
    }
};


// Most Efficient Approach
// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        // take 3 pointers, itr will point to nums1, and jtr will point to nums2, and ktr will start from nums1 end
        int itr = n-1, jtr = m-1, ktr = m + n - 1;
        
        // run untill & unless jtr become less than 0
        while(jtr >= 0){
            
            // if itr is greater is greater than 0, and num1[itr] is greater than nums1[jtr] then put the nums[itr] into nums1[ktr] and decrement itr and ktr by 1
            if(itr >= 0 && nums1[itr] > nums2[jtr]) nums1[ktr--] = nums1[itr--];
            
            // else put the nums[jtr] into nums1[ktr] and decrement jtr and ktr by 1
            else nums1[ktr--] = nums2[jtr--];
        }
    }
};
