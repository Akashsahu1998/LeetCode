
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


// 2nd Approach in Java
// Time Complexity = O(N), Space Complexity = O(N)

public String defangIPaddr(String address) {
    String str = "";
    for(int itr = 0; itr < address.length(); itr++){
        if(address.charAt(itr) == '.') str += "[.]";                
        else str += address.charAt(itr);                
    }            
    return str;
}
