/**
 * Reverse a singly-linked list.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        ListNode* nextNode = head->next;
        ListNode* newHead = reverseList(head->next);
        nextNode->next = head;
        head->next = NULL;
        return newHead;
    }
};