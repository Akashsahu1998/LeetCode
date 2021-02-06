
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


// 2nd Approach in Java
// Time Complexity = O(N^2), Space Complexity = O(N)

public int heightChecker(int[] heights) {
    int backup[] = new int[heights.length];
    for (int i = 0; i < heights.length; i++)
        backup[i] = heights[i];
    
    Arrays.sort(heights);
    
    int count = 0;
    for(int itr = 0; itr < heights.length; itr++){
        if(heights[itr] != backup[itr]) count++;
    }
    return count;
}
