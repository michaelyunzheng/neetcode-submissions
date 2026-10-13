
class Page {
public:
    string url;
    Page* prev = nullptr;
    Page* next = nullptr;

    Page(string url) : url(url) {}
};

class BrowserHistory {
private:
    Page* current;

    void clear(Page* node) {
        while (node) {
            Page* next = node->next;
            delete node;
            node = next;
        }
    }

public:
    BrowserHistory(string homepage) {
        current = new Page(homepage);
    }

    void visit(string url) {
        // Discard forward history
        clear(current->next);

        Page* newPage = new Page(url);

        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }

    string back(int steps) {
        while (steps > 0 && current->prev) {
            current = current->prev;
            steps--;
        }

        return current->url;
    }

    string forward(int steps) {
        while (steps > 0 && current->next) {
            current = current->next;
            steps--;
        }

        return current->url;
    }

    ~BrowserHistory() {
        while (current->prev) {
            current = current->prev;
        }

        clear(current);
    }
};
