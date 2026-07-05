/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> left;
        vector<int> right;

        ListNode* temp = head;
        int n =0;

        while(temp!=NULL){
            n++;
            temp = temp->next;
        }

        temp = head;

        for(int i=0; i<(n+1)/2; i++){
            left.push_back(temp->val);
            temp = temp->next;
        }

        for(int i=(n+1)/2; i<n; i++){
            right.push_back(temp->val);
            temp = temp->next;
        }
        reverse(right.begin(), right.end());

        vector<int> ans;

        int maxsize = max(left.size(), right.size());
        for(int i=0; i<maxsize; i++){
            if(i<left.size()){
                ans.push_back(left[i]);
            }
            if(i<right.size()){
                ans.push_back(right[i]);
            }
        }

        temp = head;

    for(int x : ans){
        temp->val = x;
        temp = temp->next;
    }

    }
};