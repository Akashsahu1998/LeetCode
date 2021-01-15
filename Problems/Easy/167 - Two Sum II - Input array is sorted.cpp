
// Question) 167. Two Sum II - Input array is sorted


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int itr = 0, jtr  = numbers.size()-1;
    while(itr <= jtr){
        if(numbers[itr]+numbers[jtr] == target) break;
        else if(numbers[itr]+numbers[jtr] > target) jtr--;
        else itr++;         
    }
    ans.push_back(itr+1);
    ans.push_back(jtr+1);
    return ans;
}


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public int[] twoSum(int[] numbers, int target) {
    int[] ans = new int[2]; 
    int itr = 0, jtr  = numbers.length-1;
    while(itr <= jtr){
        if(numbers[itr]+numbers[jtr] == target) break;
        else if(numbers[itr]+numbers[jtr] > target) jtr--;
        else itr++;         
    }
    ans[0] = itr+1;
    ans[1] = jtr+1;       
    return ans;
}
