
// Question) 31. Next Permutation


// Implementation

// Reference : https://www.youtube.com/watch?v=LuLCLgMElus&t=602s

// Using 2 Pointers
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    void nextPermutation(vector<int>& arr) {

        // finding first decreasing element
        int itr = arr.size()-2;
        while(itr >= 0 && arr[itr] >= arr[itr+1]) itr--;
        if(itr >= 0){

            // check from back if any element is greater than arr[itr]
            int jtr = arr.size()-1;
            while(arr[itr] >= arr[jtr]) jtr--;

            // swap both itr & jtr index values
            swap(arr[itr], arr[jtr]);
        }

        // reverse the array from itr+1 index
        reverse(arr.begin()+itr+1, arr.end());
    }
};
