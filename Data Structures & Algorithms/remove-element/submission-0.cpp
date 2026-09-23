class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> other(nums.size());
        int counter = 0;
        for (int num : nums) {
            if (num == val) {
                
            } else {
                other[counter] = num;
                counter++;
            }
        }

        nums = other;
        return counter;


    }
};