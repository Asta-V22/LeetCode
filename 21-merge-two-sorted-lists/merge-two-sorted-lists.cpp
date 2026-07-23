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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* current = dummyhead;

        while(list1!=nullptr || list2!=nullptr){
            int x = list1!=nullptr?list1->val:INT_MAX;
            int y = list2!=nullptr?list2->val:INT_MAX;

            if(x<=y){
                current->next = new ListNode(x);
                list1 = list1->next;
            }
            else{
                current->next = new ListNode(y);
                list2 = list2->next;
            }
            current = current->next;
        }

        return dummyhead->next;
    }
};