
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
