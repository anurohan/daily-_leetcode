class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* l = root;
        while(l->left){
            Node* cur = l;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            l = l->left;
        }
        return root;
    }
};