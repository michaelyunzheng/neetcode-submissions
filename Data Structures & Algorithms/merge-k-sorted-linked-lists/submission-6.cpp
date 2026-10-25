class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype(cmp)
        > minHeap(cmp);

        for (ListNode* node : lists) {
            if (node) {
                minHeap.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            current->next = node;
            current = node;

            if (node->next) {
                minHeap.push(node->next);
            }
        }

        return dummy.next;
    }
};