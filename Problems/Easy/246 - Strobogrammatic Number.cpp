
// Question) 246. Strobogrammatic Number


// Implementation

// 1st Approach
// Using Two Pointer Approach
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        // taking two pointers
        int left = 0, right = num.size()-1;
        while(left <= right){
            
            if(num[left] == '0' || num[left] == '1' || num[left] == '8' || num[right] == '0' || num[right] == '1' || num[right] == '8'){
                if(num[left] != num[right]) return false;
            }
            else if((num[left] == '6' && num[right] == '9') || (num[left] == '9' && num[right] == '6')){
                
            }
            else{
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};
