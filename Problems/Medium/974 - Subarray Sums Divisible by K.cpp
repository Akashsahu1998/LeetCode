
// Question) 974. Subarray Sums Divisible by K


// Implementation

// Using unodered_map & prefix sum
// Time Complexity = O(N), Space Complexity = O(K)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         // taking a map to store the key as a remainder and value as its fequency
        unordered_map<int, int> mp;  
        mp[0] = 1;
        int sum = 0, count = 0;
        
        for(int itr = 0; itr < nums.size(); itr++){
            // adding current element into sum
            sum += nums[itr];
            
            // finding the remainder of the sum
            int sumMod = sum % k;
            
            // to handle the negative sumMod case, i.e nums[-1,2,9], k = 2
            // whenver sumMod is less than 0, then add k into it
            if(sumMod < 0) sumMod += k;
            
            // add the frequency of sumMod into count, if its not present into map, then 0 will get added, otherwise the frequency of sumMod key will get added            
            count += mp[sumMod];
            
            // increase the frequency of sumMod into map by 1
            mp[sumMod]++;
        }
        return count;
    }
};



// Using Vector & Prefix Sum
// Time Complexity = O(N), Space Complexity = O(K)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         // taking a vector as a map to calculate the frequency of a remainder
        vector<int> mp(k+1, 0);
        mp[0] = 1;
        int sum = 0, count = 0;
        
        for(int itr = 0; itr < nums.size(); itr++){
            // adding current element into sum
            sum += nums[itr];
            
            // finding the remainder of the sum
            int sumMod = sum % k;
            
            // to handle the negative sumMod case, i.e nums[-1,2,9], k = 2
            // whenver sumMod is less than 0, then add k into it
            if(sumMod < 0) sumMod += k;
            
            // add the frequency of sumMod into count, if its not present into vector, then 0 will get added, otherwise the frequency of sumMod will get added            
            count += mp[sumMod];
            
            // increase the frequency of sumMod into map by 1
            mp[sumMod]++;
        }
        return count;
    }
};




/*
Solution Info:

1) use un_map
2) totalsum and remainder
3) check remainder into map, store into the result and incr count
*/
