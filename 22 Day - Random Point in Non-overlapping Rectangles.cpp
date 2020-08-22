
// Time Complexity O(n)

class Solution {
public:
    vector<vector<int>> rectangle;
    vector<int> rectangleArea;
    int totalArea;
    
    Solution(vector<vector<int>>& rects){
        rectangle = rects;
        int sum = 0;
        for (int itr = 0; itr < rects.size(); itr++) {
            sum += (rects[itr][2] - rects[itr][0] + 1) * (rects[itr][3] - rects[itr][1] + 1);
            rectangleArea.emplace_back(sum);
        }
        totalArea = sum;
    }
    
    vector<int> pick() {
        int randomArea = rand() % totalArea + 1;
        int itr = 0;
        for( ; itr < rectangleArea.size(); itr++) {
            if(randomArea <= rectangleArea[itr]) break;
        }
        int X = rand() % (rectangle[itr][2] - rectangle[itr][0] + 1);
        int Y = rand() % (rectangle[itr][3] - rectangle[itr][1] + 1);
        return {rectangle[itr][0] + X, rectangle[itr][1] + Y};
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
