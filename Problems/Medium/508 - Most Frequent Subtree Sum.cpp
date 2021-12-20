
// Question) 508. Most Frequent Subtree Sum


// Implementation

// Using unordered_map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int findMostFrequentSum(TreeNode* root, int &maxValue, unordered_map<int, int> &mp){
        if(!root) return 0;
        
        int leftSum = findMostFrequentSum(root->left, maxValue, mp);
        int rightSum = findMostFrequentSum(root->right, maxValue, mp);
        int totalSum = leftSum + rightSum + root->val;
        mp[totalSum]++;
        maxValue = max(maxValue, mp[totalSum]);
        return totalSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxValue = INT_MIN;
        unordered_map<int, int> mp;
        findMostFrequentSum(root, maxValue, mp);
        
        vector<int> res;
        for(auto a: mp){
            if(a.second == maxValue) res.push_back(a.first);
        }
        return res;
    }
};
