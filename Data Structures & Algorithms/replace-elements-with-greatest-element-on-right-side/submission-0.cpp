class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest = arr.back();
        arr.back() = -1;

        // stores value , assigns new value, then does comparison
        for (int i = arr.size() - 2; i > -1; i--) {
            int storage = arr[i];
            arr[i] = greatest;
            greatest = (storage > greatest) ? storage : greatest;
        }

        return arr;
    }
};