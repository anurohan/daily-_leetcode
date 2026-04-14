/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        
        while (curr != nullptr) {
            Node* dummy = new Node(0);   // Dummy head for next level
            Node* tail = dummy;          // Tail to build next level linked list
            
            // Process current level
            while (curr != nullptr) {
                // Add left child
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                // Add right child
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                // Move to next node in current level
                curr = curr->next;
            }
            
            // Move to the next level
            curr = dummy->next;
            
            // Optional: delete dummy to avoid memory leak (good practice)
            delete dummy;
        }
        
        return root;
    }
};