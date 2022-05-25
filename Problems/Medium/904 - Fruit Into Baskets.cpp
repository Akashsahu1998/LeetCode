
// Question) 904. Fruit Into Baskets


// Implementation

// Using Unordered Map
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        
        int i = 0, j = 0;
        for( ; i < fruits.size(); i++){
            mp[fruits[i]]++;
            
            if(mp.size() > 2){
                if(mp[fruits[j]]-1 == 0) mp.erase(fruits[j]);
                j++;
            }
        }
        
        return i-j;
    }
};
