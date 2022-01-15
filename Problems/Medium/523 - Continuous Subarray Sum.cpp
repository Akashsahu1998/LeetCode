
// Question) 523. Continuous Subarray Sum


// Implementation

// 1st
// Naive Approach
// Giving TLE
// Time Complexity = O(N^2), Space Complexity = O(1)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = nums[0];
        for(int itr = 1; itr < nums.size(); itr++){
            sum += nums[itr];
            if(sum % k == 0) return true;
            
            int temp = sum;
            for(int jtr = 0; jtr < itr-1; jtr++){
                temp -= nums[jtr];
                if(temp % k == 0) return true;
            }
        }
        return false;
    }
};



// 2nd
// Efficient Approach
// Using unodered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // taking a map to store the key as a remainder and value as a current index+1
        unordered_map<int, int> mp;        
        mp[0] = 0;
        int sum = 0;
        
        for(int itr = 0; itr < nums.size(); itr++){
            // adding current element into sum
            sum += nums[itr];
            
            // finding the remainder of the sum
            int sumMod = sum % k;
            
            // if remainder is present into map, then check the index of the present remainder into map, and the current index, if the length is more than or equal to 2, it means, we got the subarray of minimum length 2 
            if(mp.find(sumMod) != mp.end()){
                if(itr+1 - mp[sumMod] >= 2) return true;
            }
            else{   // if remainder is not present into map, then just put that remainder as a key and value as current index+1;
                mp[sumMod] = itr+1;
            }
        }
        return false;
    }
};



// 3rd
// Efficient Approach
// Using unodered_set
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // taking a set to store the previous remainder
        unordered_set<int> st;          
        int sum = 0, previousRem = 0;
        
        for(int itr = 0; itr < nums.size(); itr++){
            // adding current element into sum
            sum += nums[itr];
            
            // finding the remainder of the sum
            int sumMod = sum % k;
            
            // if count of sumMod in set is more than 0, it means, we got the subarray of minimum length 2 
            if(st.count(sumMod)) return true;
            
            // insert the previousRem
            st.insert(previousRem);
            previousRem = sumMod;
        }
        return false;
    }
};
