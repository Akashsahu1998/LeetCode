
// Question) 134. Gas Station


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
// We are visiting each petrol pump exactly once, therefore the time complexity is O(N)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, dist = 0, total = 0, count = 0, itr = 0, n = gas.size();
        
        while(count != n){            
           total = total + gas[itr%n];
           dist = cost[itr%n];
           
           if(total < dist){
               start = itr+1;
               total = dist = count = 0;
               if(start >= n) return -1;
           }
           else {
               count++;
               total -= dist;
           }
           
           itr++;            
       }
       
       return start;
    }
};


// 2nd Approach
// Most Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {        
        int start = 0, backupTotal = 0, total = 0;
        
        for(int itr = 0; itr < gas.size(); itr++){
            backupTotal = backupTotal + gas[itr] - cost[itr];
            if(backupTotal < 0){
                start = itr+1;
                total += backupTotal;
                backupTotal = 0;
            }
        }      
       
        return (total + backupTotal) >= 0 ? start : -1 ;
    }
};
