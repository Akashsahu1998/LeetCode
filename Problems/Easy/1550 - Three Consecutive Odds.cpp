
// Question) 1550. Three Consecutive Odds


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

bool threeConsecutiveOdds(vector<int>& arr) {
    if(arr.size() < 3) return false;
    for(int itr = 0; itr < arr.size()-2; itr++){
        if((arr[itr] % 2 == 1) && (arr[itr+1] % 2 == 1 && (arr[itr+2] % 2 == 1))) return true;
    }
    return false;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public boolean threeConsecutiveOdds(int[] arr) {
    if(arr.length < 3) return false;
    for(int itr = 0; itr < arr.length-2; itr++){
        if((arr[itr] % 2 == 1) && (arr[itr+1] % 2 == 1 && (arr[itr+2] % 2 == 1))) return true;
    }
    return false;
}
