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
            while (j >= 0 and pairs[j+1].key < pairs[j].key) {
                Pair temp = pairs[j+1];
                pairs[j+1] = pairs[j];
                pairs[j] = temp;
                j -= 1;
            }

            states.push_back(pairs);
        }

        return states;
    }
};
