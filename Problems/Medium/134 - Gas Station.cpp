
// Question) 134. Gas Station


// Implementation

// 1st Approach
// Naive Approach
// Time Complexity = O(N^2)
// Space Complexity = O(1)
// We are iterating over the each station, and calculating the cost at each station, and from each station we are trying to get the possible solution by visiting all the elements, therefore TC is O(N^2)

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
// Efficient Approach
// Time Complexity = O(N), // We are visiting each petrol pump exactly once, therefore the time complexity is O(n)
// Space Complexity = O(1)

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


// Algo Steps:
// 1) It's impossible to perform the road trip if sum(gas) < sum(cost). In this situation the answer is -1.
