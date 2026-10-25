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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype(cmp)
        > minHeap(cmp);

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            current->next = node;
            current = current->next;
            minHeap.pop();
            if (node->next != nullptr) {
                node = node->next;
                minHeap.push(node);
            } 
        }

        return dummy->next;

        // ListNode* dummy = new ListNode(0);
        // ListNode* current = dummy;
        // int empty_lists = 0;

        // for (int i = 0; i < lists.size(); i++) {
        //     if (lists[i] == nullptr) {
        //         empty_lists++;
        //     }
        // } 
        // while (empty_lists < lists.size()) {
        //     int lowest = INT_MAX;
        //     int lowest_pos = 0;
            
        //     for (int i = 0; i < lists.size(); i++) {
        //         // 1. Check if the list pointer is NOT null
        //         if (lists[i] != nullptr) { 
        //             // 2. Safe to look at the value now
        //             if (lists[i]->val < lowest) {
        //                 lowest = lists[i]->val;
        //                 lowest_pos = i;
        //             }
        //         } 
        //     }

        //     lists[lowest_pos] = lists[lowest_pos]->next;
        //     if (lists[lowest_pos] == nullptr) {
        //         empty_lists++;
        //     }
        //     current->next = new ListNode(lowest);
        //     current = current->next;
        // }
    }
};
