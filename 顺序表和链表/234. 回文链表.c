/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode **arr=(struct ListNode*)malloc(1*sizeof(struct ListNode*));
    int num=0;
    
    while(head) {
        arr[num]=head;
        num++;
        head=head->next;
        arr=(struct ListNode*)realloc(arr,(1+num)*sizeof(struct ListNode*));
    }
    num--;
    for(int i=0;i<num;i++) {
        if(arr[i]->val!=arr[num]->val) {
            free(arr);
            return false;
        }
        num--;
    }
    free(arr);
    return true;

}