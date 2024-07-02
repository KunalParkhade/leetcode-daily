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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* temp=head;
        int length=1;
        while(temp->next){
            length++;
            temp=temp->next;
        }
        k=k % length;
        temp->next=head;
        temp=head;
        for(int i=1;i<length-k;i++){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};