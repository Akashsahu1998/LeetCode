
// Question) 2130. Maximum Twin Sum of a Linked List


// Implementation

// Using Vector
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode* cur = head;        
        while(cur){
            vec.push_back(cur->val);
            cur = cur->next;
        }
        
        int maxRes = INT_MIN;
        for(int itr = 0; itr < vec.size()/2; itr++){
            int index = vec.size() - 1 - itr;            
            maxRes = max(maxRes, vec[itr]+vec[index]);
        }
        
        return maxRes;
    }
};
