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

    int getLength(ListNode* head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) {
            return nullptr; 
        }

        int len = getLength(head);

        if (len == 1) {
            return nullptr; 
        }

        int midIndex = len / 2;

        ListNode* current = head;

        // Traverse to the node just before the middle node
        for (int i = 1; i < midIndex; i++) {
            current = current->next;
        }

        // Delete the middle node
        ListNode* x = current->next;
        current->next = x->next;

        // Free the memory of the deleted node if using a language with manual memory management
        delete x;

        return head;
    }
};
