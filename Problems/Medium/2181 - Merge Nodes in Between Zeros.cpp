
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


// 2nd Approach
// Better Approach
// Without Using extra Node
// Time Complexity = O(N)
// Space Complexity = O(1), not using any extra node list

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {        
        head = head->next;
        ListNode* left = head;
        
        while(left){
            int sum = 0;
            ListNode* right = left;
            
            while(right->val != 0){
                sum += right->val;
                right = right->next;
            }
            
            left->val = sum;
            left->next = right->next;
            left = left->next;
        }
        
        return head;
    }
};
