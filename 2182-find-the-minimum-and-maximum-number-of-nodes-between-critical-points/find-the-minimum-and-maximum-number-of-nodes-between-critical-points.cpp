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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* temp=head;
        ListNode* prev=NULL;
        vector<int> a;      // it stores indices of critical points
        int i=0;
        while(temp!=NULL && temp->next!=nullptr){
            i++;
            if(prev != NULL && ((temp->val > prev->val && temp->val > temp->next->val) || 
            (temp->val < prev->val && temp->val < temp->next->val))){
                a.push_back(i);
            }
            prev=temp;
            temp=temp->next;
        }

        int n=a.size();
        if(n<2){
            return {-1, -1};
        }
        int minDistance = INT_MAX;
        for (int j = 1; j < a.size(); ++j) {
            minDistance = min(minDistance, a[j] - a[j-1]);
        }
        int maxDistance=a.back()-a.front();

        return {minDistance, maxDistance};
    }
};