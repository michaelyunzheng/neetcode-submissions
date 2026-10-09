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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* one = list1;
        ListNode* two = list2;

        ListNode dummy;
        ListNode* tail = &dummy;

        while (one && two) {
            if (one->val < two->val) {
                tail->next = one;
                one = one->next;
            } else {
                tail->next = two;
                two = two->next;
            }

            tail = tail->next;

        }
        
        tail->next = one ? one : two;

        return dummy.next;
    }
};
