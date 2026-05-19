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

    vector<int> reverse(vector<int>& ds){
        int left = 0;
        int right = ds.size()-1;

        while(left<right){
            int temp = ds[left];
            ds[left] = ds[right];
            ds[right] = temp;
            left++;
            right--;
        }
        return ds;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL ) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        int flag = 0;
        while(!q.empty()){
            vector<int> ds;
            int size = q.size();
            for(int i =0; i<size; i++){
                TreeNode* node  = q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                ds.push_back(node->val);
            }
            if(flag == 1){
                reverse(ds);
                ans.push_back(ds);
                flag = 0;
            }else{
                ans.push_back(ds);
                flag = 1;
            }
            
        }
        return ans;
    }
};