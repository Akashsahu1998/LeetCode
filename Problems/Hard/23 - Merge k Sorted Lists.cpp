
// Question) 23. Merge k Sorted Lists


// Implementation

// 1st Approach
// Not an Efficient Method
// Time Complexity = O(N * max(k.length))
// Space Complexity = O(max(k.length))=, bcz of the recursive mergeTwoLists function

// Idea : Iterating over the k lists from 1 to N, and adding all the lists into lists[0], and in last returning that lists[0], bcz all other k lists are getting merged into this lists[0]

class Solution {
private:
    // Recursive Approach to merge the sorted lists
    // Time Complexity = O(max(first, second))
    // Space Complexity = O(max(first, second)), bcz of stack trace
    ListNode* mergeTwoLists(ListNode* first, ListNode* second){
        if(!first) return second;
        if(!second) return first;        
        
        if(first->val < second->val){
            first->next = mergeTwoLists(first->next, second);
            return first;
        }
        else{
            second->next = mergeTwoLists(first, second->next);
            return second;
        }
    }
    
public:    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        // traversing over the lists
        for(int itr = 1; itr < lists.size(); itr++){
            lists[0] = mergeTwoLists(lists[0], lists[itr]);
        }
        
        return lists[0];
    }
};



// 2nd Approach
// Using Priority Queue
// Time Complexity = O(N * logK)
// Space Complexity = O(max(k.length))

// Idea: Storing all k nodes into the Priority Queue and after that just looping until its size become 0, while looping storing the top node into the dummy list, bcz it will be a smallest node, and adding the next of the kth node into Priority Queue, if its not null

class Solution {
private:
    // using this stuct to compare the data of the node, bcz we are storing the list into the Priority Queue
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // using pq to store the nodes in the ascending order, by default priority queue stores elements into ascending order only
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // storing the first node of every k lists into pq
        for(int itr = 0; itr < lists.size(); itr++){
            if(lists[itr]) pq.push(lists[itr]);
        }
        
        // Using a dummy list to store the result
        ListNode* dummy = new ListNode(0);
        
        // using the res list to return the result
        ListNode* res = dummy;
        
        // iterating over the pq, and storing the nodes into dummy, and if particular kth node is having more nodes then storing those nodes into the pq
        while(pq.size()){

            // getting the node which is on the top of pq, bcz that will be our smallest node
            ListNode* temp = pq.top();
            
            // removing the top node
            pq.pop();
            
            // storing the temp node into dummy
            dummy->next = temp;
            
            // moving dummy one step ahead
            dummy = dummy->next;
            
            // if particular kth node(temp) is having more nodes then storing the node into the pq
            if(temp->next){
                pq.push(temp->next);
            }
        }
        
        // returning the result
        return res->next;
    }
};
