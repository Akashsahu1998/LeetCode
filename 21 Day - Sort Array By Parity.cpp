
// 1st Method
// Time Complexity = O(n)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> evenVect;   // creating vector for even number
        vector<int> oddVect;    // creating vector for odd number
        
        for(int itr = 0; itr < A.size(); itr++){
            if(A[itr] % 2) oddVect.emplace_back(A[itr]);    // adding the even numbers to even vector    
            else evenVect.emplace_back(A[itr]);         // adding the odd numbers to odd vector
        }
        A.clear();  // clearing the vector to store the elements from starting 
        for(int itr = 0; itr < evenVect.size(); itr++) A.emplace_back(evenVect[itr]);   // adding even numbers in A vector
        for(int itr = 0; itr < oddVect.size(); itr++) A.emplace_back(oddVect[itr]);     // adding odd numbers in A vector
        return A;       // returning our ans
    }
};


// 2ndMethod
// Time Complexity = O(n)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {   
    for (int temp, itr = 0, jtr = 0; jtr < A.size(); jtr++)
        // if even found then we swap and increment itr, if not found then we increment jtr
        if (A[jtr] % 2 == 0) swap(A[itr++], A[jtr]);    // using swap function          
        return A;
    }
};
