
// Question) 852. Peak Index in a Mountain Array


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int peakIndexInMountainArray(vector<int>& arr) {
    return distance(arr.begin(), max_element(arr.begin(), arr.end()));
}
