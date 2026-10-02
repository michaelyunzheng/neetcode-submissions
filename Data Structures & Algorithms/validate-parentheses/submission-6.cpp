class Solution {
public:
    bool isValid(const string& s) {
        std::stack<char> brackets;

        for (char c : s) {
            if (c == '(') {
                brackets.push(')');
            } else if (c == '[') {
                brackets.push(']');
            } else if (c == '{') {
                brackets.push('}');
            } else {
                if (brackets.empty() || brackets.top() != c) {
                    return false;
                }

                brackets.pop();
            }
        }

        return brackets.empty();
    }
};