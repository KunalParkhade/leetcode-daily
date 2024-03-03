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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move first pointer to the (n+1)th node from the beginning
        for (int i = 0; i <= n; ++i) {
            if (first == nullptr) // To handle cases where n exceeds the length of the list
                return nullptr;
            first = first->next;
        }

        // Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Update the next pointer of the node before the one to be removed
        ListNode* temp = second->next;
        second->next = second->next->next;

        // Delete the node to be removed
        delete temp;

        // Store the result and clean up memory
        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};