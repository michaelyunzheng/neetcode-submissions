class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int counter = 0;
        for (int num : nums) {
            // ternary operator (short hand if else)
            counter = num ? counter + 1 : 0;

            // compare maxCount with current counter
            maxCount = max(maxCount, counter);
        
        }
        return maxCount;
    }
};