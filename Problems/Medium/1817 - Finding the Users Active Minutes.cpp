
// Question) 1817. Finding the Users Active Minutes


// Implementation

// Naive Approach
// Time Complexity = O(N^2), Space Complexity = O(N)

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, int> map, mapNUM;
        multimap <int, int> mapUAM;
        for(int itr = 0; itr < logs.size(); itr++){
            int key = logs[itr][0];
            int value = logs[itr][1];
            
            if(mapUAM.find(key) == mapUAM.end()){
                mapUAM.insert(make_pair(key, value));
                mapNUM[key]++;
            }
            else{
                 auto itr1 = mapUAM.lower_bound(key);
                 auto itr2 = mapUAM.upper_bound(key);
                 bool flag = true;   
                 while (itr1 != itr2){                    
                     if(itr1->second == value){
                         flag = false;
                         break;
                     }                    
                     itr1++;
                 }
                if(flag){
                    mapUAM.insert(make_pair(key, value));
                    mapNUM[key]++;
                }                
            }
        }
        
        for(auto mp: mapNUM) map[mp.second]++;
        
        vector<int> res(k, 0);
        for(auto mp: map) res[mp.first-1] = mp.second;
        
        return res;
    }    
};

// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> umap;
        
        for(vector<int> log: logs)
            umap[log[0]].insert(log[1]);
        
        vector<int> res(k, 0);
        for(auto itr: umap)
            res[itr.second.size()-1]++;
        
        return res;
    }    
};
