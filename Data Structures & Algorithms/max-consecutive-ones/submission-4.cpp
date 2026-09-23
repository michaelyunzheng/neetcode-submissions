class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            // ternary operator (short hand if else)
            counter = nums[i] ? counter + 1 : 0;

            // compare maxCount with current counter
            maxCount = max(maxCount, counter);
        
        }
        return maxCount;
    }
};