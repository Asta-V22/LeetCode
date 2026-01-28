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
    ListNode* deleteMiddle(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* tortoise = head;
        ListNode* hare = head->next->next;

        while(hare != nullptr && hare->next != nullptr){
            
            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        ListNode* nodeToDelete = tortoise->next;
        tortoise->next = tortoise->next->next;
        delete nodeToDelete;

        return head;
    }
};