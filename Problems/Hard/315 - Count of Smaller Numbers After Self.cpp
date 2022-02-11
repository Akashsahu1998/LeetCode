
// Question) 315. Count of Smaller Numbers After Self


// Implementation

// Reference : https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/445769/merge-sort-CLEAR-simple-EXPLANATION-with-EXAMPLES-O(n-lg-n)
// Using Merge Sort
// Time Complexity = O(NLogN)
// Space Complexity = O(N)

class Solution {
public:
    void mergeSort(vector<pair<int, int>>& originalArr, int start, int end, vector<int>& result){
        if(start >= end) return;
        
        int mid = start + ((end - start)/2);
        
        mergeSort(originalArr, start, mid, result);
        mergeSort(originalArr, mid+1, end, result);
        
        int leftIndex = start, rightIndex = mid+1, countElementsOfRightArrWhichAreLessThanLeftArr = 0;
        
        // using to create a merge array for particular partition
        vector<pair<int, int>> tempMergeArr;
        
        while(leftIndex <= mid && rightIndex <= end){
            if(originalArr[leftIndex].first > originalArr[rightIndex].first){
                
                tempMergeArr.push_back(originalArr[rightIndex]);
                
                countElementsOfRightArrWhichAreLessThanLeftArr++;
                rightIndex++;
            }
            else{
                
                result[originalArr[leftIndex].second] += countElementsOfRightArrWhichAreLessThanLeftArr;
                
                tempMergeArr.push_back(originalArr[leftIndex]);
                leftIndex++;
            }
        }
        
        while(leftIndex <= mid){
            result[originalArr[leftIndex].second] += countElementsOfRightArrWhichAreLessThanLeftArr;
            tempMergeArr.push_back(originalArr[leftIndex]);
            leftIndex++;            
        }
        
        while(rightIndex <= end){
            tempMergeArr.push_back(originalArr[rightIndex]);
            rightIndex++;
        }
        
        // copying merge array into original array
        int index = start;
        for(auto a : tempMergeArr){
            originalArr[index++] = a;
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> originalArr;
        
        for(int itr = 0; itr < n; itr++){
            originalArr.push_back({nums[itr], itr});
        }
        
        vector<int> result(n, 0);
        
        mergeSort(originalArr, 0, n-1, result);
        return result;
    }
};
