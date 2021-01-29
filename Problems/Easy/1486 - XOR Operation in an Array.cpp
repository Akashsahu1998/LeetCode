
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


// 2nd Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

int xorOperation(int n, int start) {
    int res = start+(2*0);
    for(int itr = 1; itr < n; itr++){
        res ^= start+(2*itr);
    }
    return res;
}


// 3rd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public int xorOperation(int n, int start) {
    int[] arr = new int[n];     
    for(int itr = 0; itr < n; itr++){
        arr[itr] = start+(2*itr);
    }
    int res = arr[0];
    for(int itr = 1; itr < n; itr++){
	    res = res ^ arr[itr];	
    }
    return res;
}


// 4th Approach in Java
// Time Complexity = O(N), Space Complexity = O(1)

public int xorOperation(int n, int start) {
    int res = start+(2*0);
    for(int itr = 1; itr < n; itr++){
        res ^= start+(2*itr);
    }
    return res;
}


// 5th Approach in C
// Time Complexity = O(N), Space Complexity = O(1)

int xorOperation(int n, int start){
    int res = start+(2*0);
    for(int itr = 1; itr < n; itr++){
        res ^= start+(2*itr);
    }
    return res;
}
