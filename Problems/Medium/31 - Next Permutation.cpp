
// Question) 31. Next Permutation


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int itr = arr.size()-2;
        while(itr >= 0 && arr[itr] >= arr[itr+1]) itr--;
        if(itr >= 0){
            int jtr = arr.size()-1;
            while(arr[itr] >= arr[jtr]) jtr--;
            swap(arr[itr], arr[jtr]);
        }
        reverse(arr.begin()+itr+1, arr.end());
    }
};
