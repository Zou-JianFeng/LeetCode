/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int numA=0, numB=0, diff;
    struct ListNode *p = headA;
    struct ListNode *q = headB;
    while(p){
        numA++;
        p=p->next;
    }

    while(q){
        numB++;
        q=q->next;
    }
    p=headA;
    q=headB;
    if(numB>numA){
        diff = numB - numA;
        for(int i = 0; i < diff; i++){
            q=q->next;
        }
    } else {
        diff = numA - numB;
        for(int i = 0; i < diff; i++){
            p=p->next;
        }
    }
    while(p){
        if(p==q)
            return p;
        p=p->next;
        q=q->next;
    }
    return NULL;
}