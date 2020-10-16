class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int n = 1, itr = 0, total = 0;
        while(1){
            total += n;
            
            if(total >= candies){
                n -= (total - candies);
                result[itr] += n;
                break;
            }
                        
            result[itr++] += n++;             
            
            if(itr == num_people){
                itr = 0;
            }
                     
        }        
        return result;        
    }
};
