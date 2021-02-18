
// Question) 1502. Can Make Arithmetic Progression From Sequence


// Implementation

// 1st Approach in C++
// Time Complexity = O(NlogN), Space Complexity = O(1)

bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int difference = arr[1]-arr[0];
    for(int itr = 2; itr < arr.size(); itr++){
        if(arr[itr]-arr[itr-1] != difference) return false;
    }
    return true;
}


// 2nd Approach in Java
// Time Complexity = O(NlogN), Space Complexity = O(1)

public boolean canMakeArithmeticProgression(int[] arr) {
    Arrays.sort(arr);
    int difference = arr[1]-arr[0];
    for(int itr = 2; itr < arr.length; itr++){
        if(arr[itr]-arr[itr-1] != difference) return false;
    }
    return true;
}

