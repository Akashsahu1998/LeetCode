
// Question) 2160. Minimum Sum of Four Digit Number After Splitting Digits


// Implementation

// 1st Approach
// creating all possible permutation
class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        
        while(num){
            nums.push_back(num%10);
            num /= 10;
        }
        
        sort(nums.begin(), nums.end());
        
        int n1 = (nums[0] * 10 + nums[1]) + (nums[2] * 10 + nums[3]);
        int n2 = (nums[0] * 10 + nums[2]) + (nums[1] * 10 + nums[3]);        
        int n3 = (nums[0] * 10 + nums[3]) + (nums[1] * 10 + nums[2]);
        
        int n4 = (nums[1] * 10 + nums[0]) + (nums[3] * 10 + nums[2]);
        int n5 = (nums[2] * 10 + nums[0]) + (nums[3] * 10 + nums[1]);        
        int n6 = (nums[3] * 10 + nums[0]) + (nums[2] * 10 + nums[1]);
        
        int res = min(n1, n2);
        res = min(res, n3);
        res = min(res, n4);
        res = min(res, n5);
        res = min(res, n6);        
        
        return res;
    }
};


// 2nd Approach
class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        
        while(num){
            nums.push_back(num%10);
            num /= 10;
        }
        
        sort(nums.begin(), nums.end());
        
        int n1 = nums[0] * 10 + nums[2];
        int n2 = nums[1] * 10 + nums[3];
        
        return n1 + n2;
    }
};


// 3rd Approach
class Solution {
public:
    int minimumSum(int num) {
        
        string str = to_string(num);
        
        sort(str.begin(), str.end());
        
        return ((str[0] - '0' + str[1] - '0') * 10) + (str[2] - '0' + str[3] - '0');
    }
};
