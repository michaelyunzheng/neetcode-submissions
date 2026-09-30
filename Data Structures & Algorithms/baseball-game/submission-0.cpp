#include <stack>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> score_stack;

        for (string curr : operations) {
            if (curr == "C") {
                score_stack.pop();
            } else if (curr == "D") {
                score_stack.push(score_stack.top() * 2);
            } else if (curr == "+") {
                int x = score_stack.top();
                score_stack.pop();
                int y = score_stack.top() + x;
                score_stack.push(x);
                score_stack.push(y);
            } else {
                score_stack.push(std::stoi(curr));
            }
        }

        int sum = 0;

        while (!score_stack.empty()) {
            sum += score_stack.top();
            score_stack.pop();
        }

        return sum;
        
    }

};