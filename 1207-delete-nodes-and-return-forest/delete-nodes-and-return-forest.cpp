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
     TreeNode* dfs(TreeNode* root, vector<int>& to_delete, vector<TreeNode*> &ans,unordered_set<int> &st){
        if(root==NULL){
            return NULL;
        }
        root->left = dfs(root->left, to_delete, ans,st);
        root->right = dfs(root->right, to_delete, ans,st);

        //now we are at the very bottom of our tree
        //now we'll check if this node is in the set or not
        if(st.find(root->val)!=st.end()){
            //now we have to add the left and right subtree nodes in the vector
            //before that we need to be sure that those nodes also exists
            if(root->left!=NULL){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }

            return NULL;   //by returning NULL we are disconnecting the tree at that point
        }
            return root;
}

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*> ans;
        unordered_set<int> st;      //for O(1) look up each time
        for(int x: to_delete){
            st.insert(x);
        }
        dfs(root,to_delete,ans,st);

        //from the above function we'll be removing nodes and returning trees but we also need to return the root node if it is not to be deleted
        if(st.find(root->val)==st.end()){
            ans.push_back(root);
        }
        return ans;
    }
};