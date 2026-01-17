/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* hare = head;
        ListNode* tortoise = head;

        //here we will take the advantage of the fact if there is a loop then it must hare and tortoise must meet somewhere

        while(hare != nullptr && hare->next != nullptr){
            hare = hare->next->next;
            tortoise = tortoise->next;

            if(hare == tortoise) return true;
        }
    
    return false;


    }
};