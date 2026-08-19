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
    void ps(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &temp, int &sum){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum==targetSum){
            ans.push_back(temp);
        }
        ps(root->left, targetSum, ans, temp, sum);
        ps(root->right, targetSum, ans, temp, sum);
        //now we are at a leaf point
        //check wether the sum==targetsum
        sum-=root->val;
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        ps(root, targetSum, ans, temp, sum);

        return ans;
    }
};