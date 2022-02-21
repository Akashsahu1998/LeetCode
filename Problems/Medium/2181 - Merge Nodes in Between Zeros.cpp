
// Question) 2181. Merge Nodes in Between Zeros


// Implementation

// 1st Approach
// Using extra res Node list
// Time Complexity = O(N)
// Space Complexity = O(N), using res as a extra node list, so we are considering that as a extra space

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {        
        ListNode *res = new ListNode(0), *ans = res;
        if(!head) return res;
       
        int flag = 1;
        while(head){
            if(head->val == 0 && head->next){
                ListNode* temp = head->next;
                int sum = 0;
                while(temp && temp->val != 0){
                    sum += temp->val;
                    temp = temp->next;
                }
                res->next = new ListNode(sum);
                res = res->next;
                head = temp;
            }
            else head = head->next;
        }
        res->next = NULL;
        return ans->next;
    }
};
