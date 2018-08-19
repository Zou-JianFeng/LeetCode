/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL)
        return false;
    
    struct ListNode* fast_node = head;
    struct ListNode* slow_node = head;
    
    while(fast_node != NULL && slow_node != NULL) {
        if(fast_node->next && fast_node->next->next)
            fast_node = fast_node->next->next;
        else
            return false; 
        slow_node = slow_node->next;
        if(slow_node == fast_node)
            return true;
    }
    
    return false;
}