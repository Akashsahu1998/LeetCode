
// Question) 1351. Count Negative Numbers in a Sorted Matrix.


// Implementation

// 1st Approach in C++
// Time Complexity = O(M*N), Space Complexity = O(1)

int countNegatives(vector<vector<int>>& grid) {        
    int countNegNum = 0;
    for(int itr = 0; itr < grid.size(); itr++){
        for(int btr = 0; btr < grid[itr].size(); btr++){
            if(grid[itr][btr] < 0) countNegNum++;
        }
    }
    return countNegNum;    
}


// 2nd Approach in Java
// Time Complexity = O(M*N), Space Complexity = O(1)

public int countNegatives(int[][] grid) {
    int countNegNum = 0;
    for(int itr = 0; itr < grid.length; itr++){
        for(int btr = 0; btr < grid[itr].length; btr++){
            if(grid[itr][btr] < 0) countNegNum++;
        }
    }
    return countNegNum;
}
