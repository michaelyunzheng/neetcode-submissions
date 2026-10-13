class Page {
public:
    string url_;
    Page* next = nullptr;

    Page(string url) {
        url_ = url;
    }
};

class BrowserHistory {
public:
    Page* head;
    int size;
    int pos;
    int bk = 0;

    BrowserHistory(string homepage) {
        head = new Page("dummy");
        head->next = new Page(homepage);
        size = 1;
        pos = 1;
    }
    
    void visit(string url) {
        Page* temp = head;

        if (bk == 0) {
            for (int i = 0; i < size; i++) {
                temp = temp->next;
            }
            temp->next = new Page(url);
            size++;
        } else {
            size = pos;
            bk = 0;
            for (int i = 0; i < size; i++) {
                temp = temp->next;
            }
            temp->next = new Page(url);
            size++;
        }
        pos = size;

        cout << size;
    }
    
    string back(int steps) {
        bk = 1;

        // cout << size;
        if (steps >= pos) {
            pos = 1;
            return head->next->url_;
        } else {
            pos = pos - steps;
            Page* temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            return temp->url_;
        }
    }
    
    string forward(int steps) {

        // cout << pos;
        if (pos + steps >= size) {
            pos = size;
        } else {
            pos += steps;
        }
        // cout << pos;

        Page* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp->url_;
    
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */