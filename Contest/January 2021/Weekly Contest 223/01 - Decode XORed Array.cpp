
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


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public int[] decode(int[] encoded, int first) {        
    int[] arr = new int[encoded.length+1];
    arr[0] = first;        
    for(int itr = 0, index = 1; itr < encoded.length; itr++, index++){
        arr[index] = arr[itr]^encoded[itr];
    }
    return arr;   
}
