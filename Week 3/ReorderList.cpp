// Time complexity :- O(n)
// Space complexity :- O(1)
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
ListNode* reverseList(ListNode* head) {
    
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
}
void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        
        int len = 0;
        ListNode* ptr = head;
        while(ptr)
        {
            len++;
            ptr = ptr->next;
        }

        int mid = len/2 + 1;

        ListNode* prev = NULL;
        ListNode* head2 = head;

        while(mid-- > 1)
        {
            prev = head2;
            head2 = head2->next;
        }
        prev->next = NULL;
        ListNode* head1 = head;
        head2 = reverseList(head2);


        ListNode* s = head1;
        ListNode* ptr1 = s->next;
        ListNode* ptr2 = head2->next;
        bool h1 = true;

        s->next = head2;
        s = s->next;
        while(ptr1 && ptr2)
        {
            if(h1)
            {
                s->next = ptr1;
                ptr1 = ptr1->next;
                s = s->next;
                h1 = !h1;
            }
            else
            {
                s->next = ptr2;
                ptr2 = ptr2->next;
                s = s->next;
                h1 = !h1;
            }
        }
        if(ptr1==NULL && !h1)
            s->next = ptr2;

        head = head1;
    }
};