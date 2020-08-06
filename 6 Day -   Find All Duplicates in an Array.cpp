class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> numsMap;
        for(int i = 0; i < nums.size(); i++) numsMap[nums[i]]++; 
        vector<int> duplicates;
        for(auto itr : numsMap){
            if(itr.second > 1) duplicates.emplace_back(itr.first);
        }
        return duplicates;
    }
};
