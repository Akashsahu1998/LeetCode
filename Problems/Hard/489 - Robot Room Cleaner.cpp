
// Question) 489. Robot Room Cleaner


// Implementation

// Using DFS, Backtracking & Memoization
// Time Complexity : O(4 * (N - M)) => (N - M)
// Space Complexity : O(N - M)
// Where N is a number of cells in the room and M is a number of obstacles.

class Solution {
private:
    
    // directions : up, right, down, left
    vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    // will store the row & col in a string format, so robot will not visit it again
    unordered_set<string> visited;
    
    // backtracking
    // here we have used turnRight, we can also use turnLeft, any of them we can use
    void goBack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void dfs(int row, int col, int dir, Robot& robot){
        
        // mark particular key as visited, so robot will not visit again, otherwise that path will repeat
        string key = to_string(row) + '-' + to_string(col);
        visited.insert(key);
        
        // whenever robot is moving to next step, then clean the room as well
        robot.clean();
        
        // iterating over all 4 directions
        for(int i = 0; i < 4; i++){
            
            // creating new dir, which will help in choosing new direction
            // mod it off by 4, bcz for every step, robot should check all 4 directions
            // i will run for 4 times, if dir is coming as 2, then in this case also it will check for all directions that's why mod by 4
            int newDir = (dir + i) % 4;
            
            // generating new row & new col
            int newRow = row + directions[newDir][0];
            int newCol = col + directions[newDir][1];
            
            // creating new key
            key = to_string(newRow) + '-' + to_string(newCol);
            
            // checking if key is present or not, and also checking if robot is able to move on newRow & newCol or not
            if(!(visited.find(key) != visited.end()) && robot.move()){
                dfs(newRow, newCol, newDir, robot);
                
                // backtracking
                goBack(robot);
            }
            
            // everytime turn robot right, we can also turn it left, we can use either right or left, as mentioned in the que above
            // Robot will stay in the same cell after calling turnLeft/turnRight.
            // Each turn will be 90 degrees.
            robot.turnRight();
        }
    }
    
public:
    void cleanRoom(Robot& robot) {
        dfs(0, 0, 0, robot);
    }
};


// Algo Steps
// 1) Use DFS, Backtracking, & Memoization
// 2) check for every row & col, explore all 4 directions, while exploring always move in right/left
// 3) for going back, should turn right/left, move & right/left



/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
