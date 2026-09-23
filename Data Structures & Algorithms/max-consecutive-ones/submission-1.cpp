class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            counter = nums[i] ? counter + 1 : 0;
            maxCount = max(maxCount, counter);
        
        }
        return maxCount;
    }
};