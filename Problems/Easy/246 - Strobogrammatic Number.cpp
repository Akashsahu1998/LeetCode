
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


// 2nd Approach
// Using Two Pointer Approach & Unordered Map
// Time Complexity: O(N)
// Space Complexity: O(1), we are only taking unordered map of 5 size, so it can be considered as a constant.

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'9', '6'}, {'6', '9'}};
        
        int left = 0, right = num.size()-1;
        while(left <= right){
            if(mp.find(num[left]) == mp.end() || mp[num[left]] != num[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
