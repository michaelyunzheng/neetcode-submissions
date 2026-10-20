// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> states;
        
        for (int i = 0; i < pairs.size(); i++) {
            int j = i-1;
            int k = i;
            while (j >= 0 and pairs[k].key < pairs[j].key) {
                Pair temp = pairs[k];
                pairs[k] = pairs[j];
                pairs[j] = temp;
                j -= 1;
                k -= 1;
            }
            states.push_back(pairs);

        }

        return states;
    }
};
