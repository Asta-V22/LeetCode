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
    void dfs(TreeNode* root, vector<string> &ans, vector<int> &path){
        if(root==NULL) return;

        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            //we have reached the leaf node
            string str = "";
            for(int i=0; i<path.size(); i++){
                str+=to_string(path[i]);

                if(i!=path.size()-1){
                    str+="->";
                }
            }
            ans.push_back(str);
        }
        dfs(root->left, ans, path);
        dfs(root->right, ans, path);

        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;

        dfs(root, ans, path);
        
        return ans;
    }
};