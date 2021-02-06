
// Question) 1051. Height Checker


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(N)

int heightChecker(vector<int>& heights) {
    vector<int> backup(heights);
    sort(heights.begin(), heights.end());
    int count = 0;
    for(int itr = 0; itr < heights.size(); itr++){
        if(heights[itr] != backup[itr]) count++;
    }
    return count;
}
