
// Question) 1779. Find Nearest Point That Has the Same X or Y Coordinate


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int minimumValue = -1, index = -1;
    for(int itr = 0; itr < points.size(); itr++){
        if(points[itr][0] != x && points[itr][1] != y) continue;
        
        if(minimumValue == -1){
            minimumValue = abs(x - points[itr][0]) + abs(y - points[itr][1]);
            index = itr;
            continue;
        }
        
        int var = abs(x - points[itr][0]) + abs(y - points[itr][1]);            
        if(minimumValue > var){
            minimumValue = var;
            index = itr;
        }
    }
    return index;
}
