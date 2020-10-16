
// Time Complexity = O(n)

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size();
        int dollars[366] = {0};
        
        for(auto day: days) dollars[day] = costs[0];            
        
        for(int itr = 1; itr <= days[size - 1]; itr++){
            if(!dollars[itr]) dollars[itr] = dollars[itr - 1];                
            else{
                dollars[itr] = dollars[itr - 1] + costs[0];
                int jtr = max(0, itr - 7);
                dollars[itr] = min(dollars[itr], dollars[jtr] + costs[1]);
                jtr = max(0, itr-30);
                dollars[itr] = min(dollars[itr], dollars[jtr] + costs[2]);            
            }
        }        
        return dollars[days[size - 1]];
    }
};
