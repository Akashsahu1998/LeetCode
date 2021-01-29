
// Question) 1486. XOR Operation in an Array


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

int xorOperation(int n, int start) {
    vector<int> vect;        
    for(int itr = 0; itr < n; itr++){
        vect.push_back((start+(2*itr)));
    }
    int res = vect[0];
    for(int itr = 1; itr < n; itr++){
	    res = res ^ vect[itr];	
    }
    return res;
}
