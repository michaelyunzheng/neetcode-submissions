class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                counter++;
                maxCount = max(maxCount, counter);
            } else {
                counter = 0;
            }
        }

        return maxCount;
    }
};