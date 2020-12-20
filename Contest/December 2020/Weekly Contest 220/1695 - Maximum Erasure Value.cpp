
// Question) 1695. Maximum Erasure Value


// Implementation

// 1st Approach in C++
// Using Hash Map and Window Sliding Technique
// Time Complexity = O(N), Space Complexity = O(N)

int maximumUniqueSubarray(vector<int>& nums) {
    int sum = 0, itr = 0, jtr = 0, localSum = 0;
    unordered_map<int, int> ump;
    for( ; jtr < nums.size(); jtr++){
        while(ump[nums[jtr]] >= 1){
            ump.erase(nums[itr]);
            localSum -= nums[itr];
            itr++;
        }
        ump[nums[jtr]]++;
        localSum += nums[jtr];
        sum = max(sum, localSum);
    }
    return sum;
}


// 2nd Approach in C++
// Using Hash Set and Window Sliding Technique
// Time Complexity = O(N), Space Complexity = O(N)

int maximumUniqueSubarray(vector<int>& nums) {
    int sum = 0, itr = 0, jtr = 0, localSum = 0;
    unordered_set<int> uset;
    for( ; jtr < nums.size(); jtr++){
        while(uset.find(nums[jtr]) != uset.end()){
            uset.erase(nums[itr]);
            localSum -= nums[itr];
            itr++;
        }
        uset.insert(nums[jtr]);
        localSum += nums[jtr];
        sum = max(sum, localSum);
    }
    return sum;
}
