
// Question) 1380. Lucky Numbers in a Matrix


// Implementation

// 1st Approach in C++
// Time Complexity = O(M*N), Space Complexity = O(1)																		


vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int small, big;
    vector<int> vect;
    for(int itr = 0; itr < matrix.size(); itr++){
        int ktr = 0;
        small = 999999;             
        for(int jtr = 0; jtr < matrix[0].size(); jtr++){                
            if(small > matrix[itr][jtr]){
                small = matrix[itr][jtr];
                ktr = jtr;
            }
        }
        big = small;
        for(int jtr = 0; jtr < matrix.size(); jtr++){
            big = max(big, matrix[jtr][ktr]);
        }
        if(small == big) {
            vect.push_back(small);
        }
    }
    return vect;
}


// 2nd Approach in Java
// Time Complexity = O(M*N), Space Complexity = O(1)																		

public List<Integer> luckyNumbers (int[][] matrix) {
    int small, big;
    List<Integer> list = new ArrayList<Integer>();
    for(int itr = 0; itr < matrix.length; itr++){
        int ktr = 0;
        small = 999999;             
        for(int jtr = 0; jtr < matrix[0].length; jtr++){                
            if(small > matrix[itr][jtr]){
                small = matrix[itr][jtr];
                ktr = jtr;
            }
        }
        big = small;
        for(int jtr = 0; jtr < matrix.length; jtr++){
            big = Math.max(big, matrix[jtr][ktr]);
        }
        if(small == big) {
            list.add(small);
        }
    }
    return list;
}
