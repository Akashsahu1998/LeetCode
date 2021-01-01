
// Question) 1108. Defanging an IP Address


// Implementation

// 1st Approach in C++
// Time Complexity = O(N), Space Complexity = O(N)

string defangIPaddr(string address) {
    string str;
    for(int itr = 0; itr < address.size(); itr++){
        if(address[itr] == '.') str += "[.]";                
        else str += address[itr];                
    }            
    return str;
}
