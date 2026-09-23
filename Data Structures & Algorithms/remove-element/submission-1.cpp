class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter = 0;

        for (int num : nums) {
            if (num != val) {  
                nums[counter] = num;
                counter++;
            }
        }

        return counter;
    }
};