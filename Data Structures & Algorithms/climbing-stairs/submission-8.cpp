class Solution {
public:
    map<int, int> dict;

    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        if (dict.contains(n-1) && dict.contains(n-2)) {
            return dict[n-1] + dict[n-2];
            
        } else {
            dict[n-1] = climbStairs(n-1);
            dict[n-2] = climbStairs(n-2);
        }


        return dict[n-1] + dict[n-2];
    }
};