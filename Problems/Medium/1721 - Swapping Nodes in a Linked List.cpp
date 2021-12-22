
// Question) 1721. Swapping Nodes in a Linked List


// Implementation


// 1st Approach
// Swapping the Actual Node not only value
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // if list contain only one node
        if(!head->next) return head;
        
        // finding the length of the list
        ListNode* cur = head;
        int len = 0;
        while(cur){
            cur = cur->next;
            len++;
        }
        
        // need to swap front index from start
        int front = k;
        
        // finding the index which is need to swap index from end
        int back = len - k + 1;
        
        ListNode *frontPrev = NULL, *frontNext = head->next, *frontCur = head;
        ListNode *backPrev = NULL, *backNext = head->next, *backCur = head;
        
        // moving to the respective node where we need to swap
        front--;
        back--;
        while(front || back){
            if(front){
                frontPrev = frontCur;
                frontCur = frontCur->next;
                frontNext = frontCur->next;
                front--;
            }
            if(back){
                backPrev = backCur;
                backCur = backCur->next;
                backNext = backCur->next;
                back--;
            }
        }   
        
        // if k is 1 then setting head to the last node
        if(k == 1) head = backCur;
        
        // if k == len then setting head to the first node
        if(len == k) head = frontCur;
            
        // swapping for front
        if(frontPrev && frontPrev != backCur) frontPrev->next = backCur;        
        if(frontNext != backNext) backCur->next = frontNext;
        
        // swapping for back
        if(backPrev && backPrev != frontCur) backPrev->next = frontCur;
        if(frontCur != backNext) frontCur->next = backNext;
        
        // if both node are adjacent to each other
        if(frontNext == backCur) backCur->next = frontCur;        
        if(frontCur == backNext) frontCur->next = backCur;
        
        return head;
    }
};


// 2nd Approach
// Swapping the value only
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // setting ptr1 & ptr2 to head and kthNode to null
        ListNode *ptr1 = head, *ptr2 = head, *kthNode = NULL;
        
        // running the ptr1 till kth node
        while(--k){
            ptr1 = ptr1->next;
        }
        
        // setting kth node
        kthNode = ptr1;
        
        // moving ptr1 one step ahead 
        ptr1 = ptr1->next;
        
        // taking ptr2 to the node which needs to swap from back
        while(ptr1){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        // swapping the values
        swap(kthNode->val, ptr2->val);
        
        return head;
    }
};
