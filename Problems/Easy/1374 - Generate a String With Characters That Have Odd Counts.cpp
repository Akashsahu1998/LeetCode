
// Question) 1374. Generate a String With Characters That Have Odd Counts


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

string generateTheString(int n) {
    string str = "";        
    if(!(n % 2)){   // even
        for(int itr = 0; itr < n-1; itr++) 
            str += 'a';        
        str += 'b';
    }
    else{
        for(int itr = 0; itr < n; itr++)
            str += 'a';
    }      
    return str;
}
