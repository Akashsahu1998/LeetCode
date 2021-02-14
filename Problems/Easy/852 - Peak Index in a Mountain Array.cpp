
// Question) 852. Peak Index in a Mountain Array


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int peakIndexInMountainArray(vector<int>& arr) {
    return distance(arr.begin(), max_element(arr.begin(), arr.end()));
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public int peakIndexInMountainArray(int[] arr) {
    int highestIndex = 0, maxElement = arr[0];
    for(int itr = 0; itr < arr.length; itr++){
        if(maxElement < arr[itr]){
            maxElement = arr[itr];
            highestIndex = itr;
        }
    }
    return highestIndex;
}
