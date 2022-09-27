
// Question) 28. Find the Index of the First Occurrence in a String


// Implementation

// Using two pointers
// Time Complexity : O(M*N), where M = haystack.size() and N = needle.size()
// Time Complexity : O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // travelling all possible points, it will iterate over each point untill we find the string
        for(int itr = 0 ; itr < haystack.size(); itr++){
            
            // taking two pointers
            // using i for iterating over haystack to match the value with needle
            // using j for iterating over needle to match the value with haystack
            int i = itr, j = 0;
            
            while(i < haystack.size() && j < needle.size() && haystack[i] == needle[j]){
                i++;
                j++;
            }
            
            // got result
            if(j == needle.size()){
                return itr;
            }
        }
        
        // needle string didn't find, so return -1
        return -1;
    }
};

// "mississippi"
// "issip"
// bcz of this example, we are travelling all possible points

// algo steps
// 1) use two pointers, and travel all possible index and try to match the string with needle
