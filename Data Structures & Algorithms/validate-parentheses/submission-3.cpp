class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> bracketDict;
        bracketDict['{'] = '}';
        bracketDict['('] = ')';
        bracketDict['['] = ']';

        std::stack<char> brackets;
        int N = s.length();
        for (const char& c: s) {
            if (c == '(' || c == '{' | c == '[') {
                brackets.push(c);
                cout << "here";
            } else {
                if (brackets.size() == 0) {
                    return false;
                } 

                if (bracketDict[brackets.top()] == c) {
                    brackets.pop();
                    cout << "where?";
                } else {
                    return false;
                }
            }
        }

        if (brackets.size() != 0) {
            return false;
        }
        return true;
    }
};
