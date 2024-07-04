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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        ListNode* temp = head->next; // Skipping the initial zero node

        long long sum = 0; //long long to prevent overflow

        while (temp != nullptr) {
            if (temp->val == 0) {
                result->next = new ListNode(sum);
                result = result->next;
                sum = 0;
            } else {
                sum += temp->val;
                // Check for overflow
                if (sum > INT_MAX) {
                    // Handle overflow case, you may throw an exception or handle it accordingly
                    throw std::overflow_error("Sum exceeds integer limit");
                }
            }
            temp = temp->next;
        }

        return dummy->next; // Skip the initial dummy node
    }
};