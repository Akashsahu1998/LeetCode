
// Question) 237. Delete Node in a Linked List


// Implementation

// Time Complexity = O(1), Space Complexity = O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};
