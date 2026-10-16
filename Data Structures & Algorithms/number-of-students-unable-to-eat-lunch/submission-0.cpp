class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        size_t st_qty = students.size(); 
        size_t sw_qty = sandwiches.size();
        size_t matched = 0;
        for (int i = 0; i < sw_qty; i++) {
            bool noMatch = true;
            for (int j = 0; j < st_qty; j++) {
                if (students[j] == 2) {
                    continue;
                }
                
                if (sandwiches[i] == students[j]) {
                    sandwiches[i] = 2;
                    students[j] = 2;
                    matched++;
                    noMatch = false;
                    break;
                } 
            }

            if (noMatch) {
                return (st_qty - matched);

            }


        }

        return (st_qty - matched);
    }
};