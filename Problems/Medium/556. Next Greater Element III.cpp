
// Que) 556. Next Greater Element III

// Implementation

// Question is same as finding the next permutation of a number

// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:    
    int nextGreaterElement(int n) {        
        // converting number digits into string, not in array bcz of the memory overflow issue
        string str = to_string(n);
        
        // traversing from back and checking if any index is having element lesser than the its index+1         // i.e => 6,5,3,7,4,2,1 => on index 2 we are getting smaller element
        int itr = str.size()-2;
        while(itr >= 0 && str[itr] >= str[itr+1]){            
            itr--;
        }
        
        // it means number is already max
        // means number is in decreasing order
        // i.e => 3,2,1
        if(itr == -1) return -1;
        
        // finding the next greater element of str[itr] from end        
        int jtr = str.size()-1;
        while(str[itr] >= str[jtr]){
            jtr--;
        }
        
        // after getting, we will swap the itr and jtr position element
        swap(str[itr], str[jtr]);
        
        // reverse all the elements from itr+1 to end;
        reverse(str.begin()+itr+1, str.end());
        
        // convert back into long(not in int bcz of the memory overflow issue)
        long res = stol(str);

        // if its more than INT_MAX or its equal to n means no change, then return -1, otherwise res
        return (res > INT_MAX || res == n) ? -1 : res;
    }
};

// Using predefined function
// Another approach
class Solution {
public:    
    int nextGreaterElement(int n) {  
        // converting number digits into string
        string str = to_string(n);
        
        // C++ STL function used to get the next permutation of a number
        next_permutation(begin(str), end(str));
                
        // convert back into long(not in int bcz of the memory overflow issue)
        long res = stol(str);
        
        // if its more than INT_MAX or its equal to n means no change, then return -1, otherwise res
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};


// Test Cases
// 2147483486
// 12443322
// 112
// 12
// 21
// 49
// 56
// 32
// 15
// 49
// 65
// 99
// 101
// 213
// 5163
// 4236
// 4667
// 318674
// 6547321

// ans
// -1
// 13222344
// 121
// 21
// -1
// 94
// 65
// -1
// 51
// 94
// -1
// -1
// 110
// 231
// 5316
// 4263
// 4676
// 318746
// 6571234
