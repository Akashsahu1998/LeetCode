
// Question) 2138. Divide a String Into Groups of Size k


// Implementation

// Time Complexity = O(N), Space Complexity = O(1) for space complexity, not considering vector bcz its a part of output
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        
        for(int itr = 0; itr < s.size(); itr += k){
            string str = s.substr(itr, k);
            ans.push_back(str);
        }
                
        string lastStr = ans[ans.size()-1];
        int lastIndexSize = lastStr.size();
        
        if(lastIndexSize != k){
            for(int itr = 0; itr < k-lastIndexSize; itr++)   {
                lastStr = lastStr + fill;
            }
        }
        
        ans[ans.size()-1] = lastStr;
        
        return ans;
    }
};
