class Solution {
public:
    ListNode* mergesortednodes(ListNode* left, ListNode* right) {
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;

        while (left != nullptr && right != nullptr) {
            // Updated 'data' to 'val' to match the struct definition
            if (right->val <= left->val) {
                temp->next = right;
                right = right->next;
            } else {
                temp->next = left;
                left = left->next;
            }
            temp = temp->next;
        }

        if (left != nullptr) temp->next = left;
        else temp->next = right;

        ListNode* result = dummynode->next;
        delete dummynode; // Good memory management!
        return result;
    }

    ListNode* findmid(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* tortoise = head;
        ListNode* hare = head->next; // Starts one step ahead for correct split

        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise;
    }

    // Renamed from Merge to sortList for consistency
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // 1. Find mid and split
        ListNode* mid = findmid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode* left = head;

        // 2. Recurse
        left = sortList(left);
        right = sortList(right);

        // 3. Merge
        return mergesortednodes(left, right);
    }
};