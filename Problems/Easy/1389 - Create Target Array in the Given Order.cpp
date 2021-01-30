
// Question) 1389. Create Target Array in the Given Order


// Implementation

// 1st Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public int[] createTargetArray(int[] nums, int[] index) {        
    LinkedList<Integer> ll = new LinkedList<Integer>();
    for(int itr = 0; itr < nums.length; itr++){
        ll.add(index[itr], nums[itr]);
    }
    
    int[] targetArray = new int[nums.length];
    int itr = 0;
    for(Integer list : ll){
        targetArray[itr++] = list;
    }        
    return targetArray;
}
    

// 2nd Approach in c++
// Time Complexity = O(N * M), Space Complexity = O(1)

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> targetArray;
    for(int itr = 0; itr < index.size(); itr++){
        targetArray.insert(targetArray.begin()+index[itr], nums[itr]);
    }           
    return targetArray;
}
