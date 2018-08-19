/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 && !l2) return NULL;
    if (!l1) return l2;
    if (!l2) return l1;
    struct ListNode *head, *p;
    (l1->val < l2->val) ? (head = l1) : (head = l2);
    (l1->val < l2->val) ? (l1 = l1->next) : (l2 = l2->next);
    p = head;
    while (l1 && l2) {
        p = p->next;
        (l1->val < l2->val) ? (p->next = l1) : (p->next = l2);
        (l1->val < l2->val) ? (l1 = l1->next) : (l2 = l2->next);
        p = p->next;
    }
    if (l1) p->next = l1;
    if (l2) p->next = l2;
    
    return head;
}