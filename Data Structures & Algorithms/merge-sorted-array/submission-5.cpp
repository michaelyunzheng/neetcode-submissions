class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> place;
        
        int i = 0;
        int j = 0;

        while (i < m and j < n) {
            if (nums1[i] < nums2[j]) {
                place.push_back(nums1[i++]);
            } else {
                place.push_back(nums2[j++]);    
            }
        }

        while (i < m) {
            place.push_back(nums1[i++]);
        }

        while (j < nums2.size()) {
            place.push_back(nums2[j++]);
        }

        nums1 = place;
    }
};