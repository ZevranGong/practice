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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next){
            return head;
        }
        ListNode* start = NULL;
        ListNode* prev = NULL;
        ListNode* dup = NULL;
        while(head){
            //check if head is duplicate
            while (head->next && head->val == head->next->val){
                dup = head;
                head->next = head->next->next;
            }
            //@assert: head->next==NULL || head->val != head->next->val
            //head is not duplicate, hence we need to push head into
            //final linked list
            if (dup != head){
                if (!prev){
                    //head is the first node
                    prev = head;
                    start = head;
                } else{
                    //head is an intermediate node
                    prev->next = head;
                    prev = head;
                }
            }
            head = head -> next;
        }
        //Remember to set prev->next to null ONLY WHEN prev exists
        if (prev) prev->next = NULL;
        return start;
    }
};