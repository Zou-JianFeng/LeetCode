/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* ptr = head;
    while(ptr && ptr->val == val) {
         ptr = ptr->next;
    }
    head = ptr;
    while(ptr && ptr->next) {
        if(ptr->next->val == val)
            ptr->next = ptr->next->next;
        else
            ptr = ptr->next;
    }
    return head;
}