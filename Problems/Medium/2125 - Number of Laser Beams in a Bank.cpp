
// Question) 2125. Number of Laser Beams in a Bank


// Implementation

// Naive Approach
// Time Complexity = O(N*M), Space Complexity = O(N)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> vec;
        for(int itr = 0; itr < bank.size(); itr++){
            int count = 0;
            
            for(auto s : bank[itr]){
                if(s == '1') count++;
            }         
            if(count) vec.push_back(count);
        }
        
        if(vec.size() == 0) return 0;
        
        int res = 0;
        for(int itr = 0; itr < vec.size()-1; itr++){
            res += vec[itr] * vec[itr+1];
        }
        
        return res;
    }
};


// Efficient Approach
// Time Complexity = O(N*M), Space Complexity = O(1)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {        
        int res = 0, prev = 0;        
        for(int itr = 0; itr < bank.size(); itr++){
            int cnt = count(bank[itr].begin(), bank[itr].end(), '1');            
            res += cnt * prev;
            if(cnt > 0) prev = cnt;
        }
        
        return res;
    }
};
