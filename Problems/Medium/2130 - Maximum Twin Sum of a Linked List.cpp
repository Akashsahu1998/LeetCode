
// Question) 2130. Maximum Twin Sum of a Linked List


// Implementation

// 1st
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


// 2nd
// Using Stack
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* cur = head;
        
        // storing the all values from linked list into stack
        while(cur){
            st.push(cur->val);
            cur = cur->next;
        }
        
        cur = head;
        int n = st.size();        
        int maxRes = INT_MIN;
        
        // running stack till the half of its size        
        while(st.size() > n/2){
            maxRes = max(maxRes, st.top() + cur->val);            
            st.pop();
            cur = cur->next;
        }
        
        return maxRes;
    }
};
