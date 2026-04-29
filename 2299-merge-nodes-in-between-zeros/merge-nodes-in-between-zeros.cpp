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
       ListNode* left = head->next;
       ListNode* right = head->next;
       int sum = 0;
       while(right!=NULL){
        if(right->val==0){
            left->val = sum;
            right = right->next;
            left->next = right;
            left = right;
            sum = 0;
        }
        else{
        sum+=right->val;
        right = right->next;
        }
       }
        return head->next;
    }
};