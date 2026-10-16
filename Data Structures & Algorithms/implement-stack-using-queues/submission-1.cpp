#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    void push(int x) {
        q.push(x);

        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

// #include <iostream>
// #include <queue>

// class MyStack {
// public:
//     std::queue<int> qA;
//     std::queue<int> qB;
//     MyStack() {

//     }
    
//     void push(int x) {
//         qB.push(x);

//         while (!qA.empty()) {
//             qB.push(qA.front());
//             qA.pop();
//         }

//         qA = qB;
//         qB = std::queue<int>();
//     }
    
//     int pop() {
//         int x = qA.front();
//         qA.pop();
//         return x;
//     }
    
//     int top() {
//         return qA.front();
//     }
    
//     bool empty() {
//         return qA.empty();
//     }
// };

// /**
//  * Your MyStack object will be instantiated and called as such:
//  * MyStack* obj = new MyStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * bool param_4 = obj->empty();
//  */