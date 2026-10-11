class ListNode {
public: 
    int val_;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;

    ListNode(int val) {
        val_ = val;
    }

};

class MyLinkedList {
public:
    ListNode* head;
    ListNode* tail;
    
    MyLinkedList() {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        ListNode* test = head;

        for (int i = -1; i < index; i++) {
            if (test->next != nullptr) {
                test=test->next;        
            } else {
                return -1;
            }
        }

        return test->val_;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->prev = head;
        newNode->next = head->next;

        head->next->prev = newNode;
        head->next = newNode;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = tail;
        newNode->prev = tail->prev;

        tail->prev->next = newNode;
        tail->prev = newNode;
    }
    
    void addAtIndex(int index, int val) {
        
        ListNode* test = head;

        for (int i = -1; i < index; i++) {
            if (test->next != nullptr) {
                test=test->next;        
            } else {
                return;
            }
        }

        ListNode* newNode = new ListNode(val);

        newNode->prev = test->prev;
        newNode->next = test;

        test->prev->next = newNode;
        test->prev = newNode;

        cout << head->next->val_;
        cout << head->next->next->val_;
        cout << head->next->next->next->val_;
    }
    
    void deleteAtIndex(int index) {
        ListNode* test = head;

        for (int i = -1; i < index; i++) {
            if (test->next != nullptr) {
                test=test->next;        
            } else {
                return;
            }
        }

        if (test != tail) {
            test->prev->next = test->next;
            test->next->prev = test->prev;
        }
    }

    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */