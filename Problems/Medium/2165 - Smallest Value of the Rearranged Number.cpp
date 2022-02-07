
// Question) 2165. Smallest Value of the Rearranged Number


// Implementation

// 1st Approach
// Using one extra array
// Time Complexity = O(NLogN) suppose N is :- Total number of digits in num
// Space Complexity = O(N)

class Solution {
public:
    long long smallestNumber(long long num) {        
        vector<long long> arr;
        
        // converting num into array
        while(num){
            arr.push_back(num%10);
            num /= 10;
        }
        
        // if num is greater than equal to 0, it means we need to to sort it into ascending order to make it smallest
        if(num >= 0){
            sort(arr.begin(), arr.end());
            
            // but when we are sorting it into ascending order, then 0 can come at 0th index, so we need to count the total 0, then count+1 index and 0th index we need to swap, to remove the leading 0's
            if(arr.size() >= 2){
                
                long long i = 0;
                
                while(i < arr.size() && arr[i] == 0) i++;
                
                swap(arr[0], arr[i]);
            }
        }   // if num is negative, it means we need to to sort it into descending order to make it smallest
        else{
            sort(arr.begin(), arr.end(), greater<int>());
        }
        
        // after all process, we need to convert our array back to num to return the result
        long long n = 0;
        for(long long itr = 0; itr < arr.size(); itr++){
            n = n * 10 + arr[itr];
        }
        
        return n;
    }
};



// 2nd Approach
// Using extra string
// Time Complexity = O(NLogN) suppose N is :- Total number of digits in num
// Space Complexity = O(N), considering string of N size

class Solution {
public:
    long long smallestNumber(long long num) {
        
        // convert num into string
        string str = to_string(num);
        
        // if num is greater than 0, it means we need to to sort it into ascending order to make it smallest
        if(num > 0){
            sort(str.begin(), str.end());
            
            // but when we are sorting it into ascending order, then '0' can come at 0th index, so we need to count the total '0', then count+1 index and 0th index we need to swap, to remove the leading 0's
            int i = 0;                
            while(i < str.size() && str[i] == '0') i++;
            
            swap(str[i], str[0]);
        }   // if num is negative, it means we need to to sort it into descending order to make it smallest
        else if(num < 0){
            sort(str.rbegin(), str.rend());
            return -stoll(str); // convert back into long long and also appending the - sign
        }
        return stoll(str);
    }
};
