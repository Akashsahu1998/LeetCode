
// Question-1) 1720. Decode XORed Array


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> vect{first};        
    for(int itr = 0; itr < encoded.size(); itr++){
        vect.emplace_back(vect.back()^encoded[itr]);            
    }
    return vect;
}
