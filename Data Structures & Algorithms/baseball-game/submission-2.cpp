#include <stack>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> ss;
        int total = 0;
        for (const string& curr : operations) {
            if (curr == "C") {
                total -= ss.top();
                ss.pop();
            } else if (curr == "D") {
                total += (ss.top() * 2);
                ss.push(ss.top() * 2);
            } else if (curr == "+") {
                int x = ss.top();
                ss.pop();
                int y = ss.top() + x;
                ss.push(x);
                ss.push(y);
                total += y;
            } else {
                int y = std::stoi(curr);
                ss.push(y);
                total += y;
            }
        }

        

        return total;
        
    }

};