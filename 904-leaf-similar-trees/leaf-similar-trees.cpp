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
private:
    void leaf(TreeNode* root, vector<int> &arr){
        if(root==NULL){
            return;
        }
        leaf(root->left, arr);
        leaf(root->right,arr);
        if(!root->left && !root->right){
            arr.push_back(root->val);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        leaf(root1, tree1);
        leaf(root2, tree2);

        if(tree1 == tree2){
            return true;
        }
        return false;

    }
};