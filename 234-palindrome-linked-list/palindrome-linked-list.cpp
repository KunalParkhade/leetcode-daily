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
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        while(head){
            list.push_back(head->val);
            head=head->next;
        }

        int left=0, right=list.size()-1;
        while(left<right){
            if(list[left]!=list[right]){
                return false;
            }
            else{
                left++;
                right--;
            }
        }

        return true;
    }
};