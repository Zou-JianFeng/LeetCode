/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head) return NULL;
    if (!head->next) return head;
    
    struct ListNode* t = head->next->next;
    head->next->next = head;
    head = head->next;
    head->next->next = t;
    if (!t) return head;
        
    struct ListNode *p1, *p2;
    p1 = head->next;
    p2 = p1->next;
    while (p2->next){
        p1->next = p2->next;
        p2->next = p2->next->next;
        p1->next->next = p2;
        if (!p2->next) break;
        p1 = p2;
        p2 = p2->next;
    }
    return head;

}