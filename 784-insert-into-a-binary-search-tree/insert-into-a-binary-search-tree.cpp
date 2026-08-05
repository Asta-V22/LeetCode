/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);

        TreeNode* head = root;
        TreeNode* newNode = new TreeNode(val);
        TreeNode* prevNode = nullptr;

        while(head!=nullptr){
            if(head->val<val){
                prevNode = head;
                head = head->right;
            }
            else if(head->val>val){
                prevNode = head;
                head=head->left; 
            }
        }

        if(prevNode->val<val){
            prevNode->right = newNode;
        }
        else{
            prevNode->left=newNode;
        }

        return root;
        
    }
};