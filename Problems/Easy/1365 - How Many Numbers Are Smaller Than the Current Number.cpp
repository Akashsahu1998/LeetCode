
// Question) 1365. How Many Numbers Are Smaller Than the Current Number


// Implementation

// 1st Approach in C++
// Time Complexity = O(N^2), Space Complexity = O(N)

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int size = nums.size();
    vector<int> vect;
    for(int itr = 0; itr < size; itr++){
        int cnt = 0, temp = size-1, jtr = itr+1;
        while(temp-- > 0){
            if(jtr == size) jtr = 0;
            if(nums[itr] > nums[jtr++]) cnt++;                                                    
        }
        vect.emplace_back(cnt);
    }
    return vect;
}


// 2nd Approach in Java
// Time Complexity = O(N^2), Space Complexity = O(N)

public int[] smallerNumbersThanCurrent(int[] nums) {                
    int size = nums.length;
    int[] arr = new int[size];
    for(int itr = 0; itr < size; itr++){
        int cnt = 0, temp = size-1, jtr = itr+1;
        while(temp-- > 0){
            if(jtr == size) jtr = 0;
            if(nums[itr] > nums[jtr++]) cnt++;                                                    
        }
        arr[itr] = cnt;
    }
    return arr;
}
