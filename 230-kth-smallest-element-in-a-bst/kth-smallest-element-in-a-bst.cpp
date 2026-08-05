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
    int result = -1;
private:
    void inorder(TreeNode* root, int &k){
        if(root==NULL) return;

        inorder(root->left, k);

        k--;     //we have traversed one of the smallest one
        if(k==0){ // i.e. we reach our number
            result = root->val;
            return;
        }
        else{
            inorder(root->right, k);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};