
// Question) 1313. Decompress Run-Length Encoded List


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> vect;
    for(int itr = 0; itr < nums.size(); itr++){
        int freq = nums[itr++];
        int val = nums[itr];
        for(int jtr = 0; jtr < freq; jtr++) vect.push_back(val);
    }
    return vect;
}


// 2nd Approach in C++
// Using insert

// Time Complexity = O(N), Space Complexity = O(N)

vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> vect;
    for(int itr = 0; itr < nums.size(); itr += 2)
        vect.insert(vect.end(), nums[itr], nums[itr+1]);
    return vect;
}


// 3rd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public int[] decompressRLElist(int[] nums) {
    int size = 0;
    for(int itr = 0; itr < nums.length; itr += 2){
        size += nums[itr];
    }
    
    int[] arr = new int[size];        
    for(int itr = 0, index = 0; itr < nums.length; itr++){
        int freq = nums[itr++];
        int val = nums[itr];
        for(int jtr = 0; jtr < freq; jtr++) arr[index++] = val;
    }
    return arr;
}
