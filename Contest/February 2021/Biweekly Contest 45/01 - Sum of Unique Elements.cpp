
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


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public int sumOfUnique(int[] nums) {
    Map<Integer, Integer> umap = new HashMap<Integer, Integer>();
    for(int itr = 0; itr < nums.length; itr++){
        if(umap.containsKey(nums[itr])) umap.put(nums[itr], umap.get(nums[itr])+1);
        else umap.put(nums[itr], 1);
    }
    int sum = 0;
    for(Integer entry : umap.keySet()){
        if(umap.get(entry) == 1) sum += entry;
    }
    return sum;
}


