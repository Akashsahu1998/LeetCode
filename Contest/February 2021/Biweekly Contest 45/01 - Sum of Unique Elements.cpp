
// Question-1) 1748 - Sum of Unique Elements


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> umap;
    for(int itr = 0; itr < nums.size(); itr++){
        umap[nums[itr]]++;
    }
    int sum = 0;
    for(auto a : umap){
        if(a.second == 1) sum += a.first;
    }
    return sum;
}



