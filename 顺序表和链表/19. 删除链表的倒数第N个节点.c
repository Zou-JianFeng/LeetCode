/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *temp = head,*del;
    struct ListNode* arr[n+1];
    int i=0;
    
    while(temp){
        arr[i] = temp;
        printf("%d %d\n",i,temp->val);
        temp = temp -> next;
        
        if(i == n){
            i = 0;
        } else {
            i++;
        }
    }
    
    temp = arr[i];
    del = (i==n ? arr[0] : arr[++i]);
    
    if(del == head){
        head = head->next;
    } else {
        temp->next = del->next;
    }
    
    free(del);
    return head;
}