
struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;

    ListNode(int value) : val(value) {}
};

class MyLinkedList {
private:
    ListNode* head;
    ListNode* tail;
    int size = 0;

    // Assumes index refers to a valid real node.
    ListNode* nodeAt(int index) {
        if (index < size / 2) {
            ListNode* curr = head->next;

            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }

            return curr;
        } else {
            ListNode* curr = tail->prev;

            for (int i = size - 1; i > index; i--) {
                curr = curr->prev;
            }

            return curr;
        }
    }
    
    void insertBefore(ListNode* nextNode, int val) {
        ListNode* prevNode = nextNode->prev;
        ListNode* newNode = new ListNode(val);

        newNode->prev = prevNode;
        newNode->next = nextNode;

        prevNode->next = newNode;
        nextNode->prev = newNode;

        size++;
    }

public:
    MyLinkedList() {
        head = new ListNode(-1);
        tail = new ListNode(-1);

        head->next = tail;
        tail->prev = head;
    }

    // Avoid accidental shallow copies of owned pointers.
    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList& operator=(const MyLinkedList&) = delete;

    ~MyLinkedList() {
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        return nodeAt(index)->val;
    }

    void addAtHead(int val) {
        insertBefore(head->next, val);
    }

    void addAtTail(int val) {
        insertBefore(tail, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }

        if (index <= 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        insertBefore(nodeAt(index), val);
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        ListNode* curr = nodeAt(index);

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
        size--;
    }
};
