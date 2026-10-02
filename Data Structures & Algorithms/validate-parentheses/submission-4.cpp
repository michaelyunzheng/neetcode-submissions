class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> bracketDict;
        bracketDict['{'] = '}';
        bracketDict['('] = ')';
        bracketDict['['] = ']';

        std::stack<char> brackets;

        for (const char& c: s) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } else {
                if (brackets.empty()) {
                    return false;
                } 

                if (bracketDict[brackets.top()] != c) {
                    return false;
                } 

                brackets.pop();
            }
        }

        return brackets.empty();
    }
};
