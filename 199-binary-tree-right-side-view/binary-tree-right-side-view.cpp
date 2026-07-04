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
    vector<int> rightSideView(TreeNode* root) {

        if(root == nullptr) return {};
        queue<pair<TreeNode*,int>> q;
        map<int,int> mp;

        q.push({root,0});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.second;

            mp[x] = temp.first->val;

            if(temp.first->left){
                q.push({temp.first->left,x+1});

            }
            if(temp.first->right){
                q.push({temp.first->right, x+1});
            }
        }

        vector<int> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};