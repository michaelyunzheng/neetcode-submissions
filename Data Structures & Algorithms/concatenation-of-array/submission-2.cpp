class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // vector<int> ans = nums;
        // ans.insert(ans.end(), nums.begin(), nums.end());
        // return ans;

        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};