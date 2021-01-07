
// Question) 709. To Lower Case


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(1)

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower); 
    return str;
}
