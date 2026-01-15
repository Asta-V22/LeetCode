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
    ListNode* middleNode(ListNode* head) {
        if(head->next==nullptr) return head;
        ListNode* hare = head;
        ListNode* turtle = head;

        //below was my more complicated but self done approach the secons one is the improvement on it
        // while(hare){
        //     if(hare->next==nullptr){
        //         return turtle;
        //     }
        //     else if(hare->next->next == nullptr){
        //         return turtle->next;
        //     }
        //     hare = hare->next->next;
        //     turtle = turtle->next;
        // }
        // return head;

        while(hare != nullptr && hare->next != nullptr){
            turtle = turtle->next;
            hare = hare->next->next;
        }
        return turtle;
    }
};