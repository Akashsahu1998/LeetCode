
// Question) 426. Convert Binary Search Tree to Sorted Doubly Linked List


// Implementation

// Using DFS
// Time Complexity = O(N)
// Space Complexity = O(N), Bcz of recursion call stack, In case of Balanced Binary Tree its O(logN), but in worst case(Unbalanced Binary Tree) it will be O(N).
// Idea : Doing Preorder Traversal

class Solution {
private:
    void dfs(Node *curNode, Node *&lastVisitedNode, Node *&firstVisitedNode){
        // if curNode is not null
        if(curNode){
            
            // make left call
            dfs(curNode->left, lastVisitedNode, firstVisitedNode);
            
            // if lastVisitedNode is not null, we can make the connection b/w the cur & lastVisitedNode
            // but(else), if its null, then we know we got the firstVisitedNode, so we can use it later
            if(lastVisitedNode){
                lastVisitedNode->right = curNode;
                curNode->left = lastVisitedNode;
            }
            else{
                firstVisitedNode = curNode;
            }
            
            // updating the lastVisitedNode, bcz now curNode will become the lastVisitedNode
            lastVisitedNode = curNode;            
            
            // make right call
            dfs(curNode->right, lastVisitedNode, firstVisitedNode);
        }
    }
    
public:
    Node* treeToDoublyList(Node* curNode) {
        
        // base case
        if(!curNode) return NULL;
        
        // will pass lastVisitedNode and firstVisitedNode by address in DFS()
        Node* lastVisitedNode = NULL, *firstVisitedNode = NULL;
        dfs(curNode, lastVisitedNode, firstVisitedNode);
        
        // pointing last node to first node & vice versa, bcz we need to create Circular Linked List
        lastVisitedNode->right = firstVisitedNode;
        firstVisitedNode->left = lastVisitedNode;
        
        return firstVisitedNode;
    }
};
