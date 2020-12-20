
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


// 3rd Approach in Java
// Using Hash Map and Window Sliding Technique
// Time Complexity = O(N), Space Complexity = O(N)

public int maximumUniqueSubarray(int[] nums) {
    int sum = 0, itr = 0, jtr = 0, localSum = 0;
    HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
    for( ; jtr < nums.length; jtr++){
        while(hmap.containsKey(nums[jtr])){
            hmap.remove(nums[itr]);                
            localSum -= nums[itr];
            itr++;
        }
        
        if (hmap.containsKey(nums[jtr])) 
            hmap.put(nums[jtr], hmap.get(nums[jtr]) + 1); 
        else 
            hmap.put(nums[jtr], 1);              
        localSum += nums[jtr];
        sum = Math.max(sum, localSum);
    }
    return sum;
}


// 4th Approach in Java
// Using Hash Set and Window Sliding Technique
// Time Complexity = O(N), Space Complexity = O(N)

public int maximumUniqueSubarray(int[] nums) {
    int sum = 0, itr = 0, jtr = 0, localSum = 0;
    HashSet<Integer> hset = new HashSet<Integer>();
    for( ; jtr < nums.length; jtr++){
        while(hset.contains(nums[jtr])){
            hset.remove(nums[itr]);                
            localSum -= nums[itr];
            itr++;
        }
        hset.add(nums[jtr]);
        localSum += nums[jtr];
        sum = Math.max(sum, localSum);
    }
    return sum;
}
