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
    bool pathsum(TreeNode* root, int targetSum, int sum){
        if(root==NULL){
            return false;               
        }
        sum+=root->val;

        if(!root->left && !root->right && sum==targetSum){
            return true;
        }

        bool left = pathsum(root->left, targetSum, sum);
        bool right = pathsum(root->right, targetSum, sum);

        return left || right;

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int  sum = 0;
        return pathsum(root,targetSum, sum);
    }
};